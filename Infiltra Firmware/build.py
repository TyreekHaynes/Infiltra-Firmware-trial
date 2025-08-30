# build.py
from typing import TYPE_CHECKING, Any
if TYPE_CHECKING:
    Import: Any = None
    env: Any = {}
Import("env")

from SCons.Script import AlwaysBuild
import os

# Keep your original warning suppression (unchanged)
env.Append(CXXFLAGS=["-Wno-conversion-null"])

def _chip() -> str:
    mcu = (env.BoardConfig().get("build.mcu", "esp32") or "esp32").lower()
    return {
        "esp32": "esp32",
        "esp32s2": "esp32s2",
        "esp32s3": "esp32s3",
        "esp32c3": "esp32c3",
    }.get(mcu, "esp32")

def _offsets(chip: str):
    boot = "0x1000" if chip == "esp32" else "0x0"
    return boot, "0x8000", "0x10000"

def _get_out_dir() -> str:
    # Allow configuring an absolute output directory (handles spaces, env vars)
    try:
        opt = env.GetProjectOption("merge_out_dir")
    except Exception:
        opt = None
    if opt:
        return os.path.normpath(os.path.expandvars(opt))
    # Fallback to project ./files
    return os.path.join(env.subst("$PROJECT_DIR"), "files")

def _merge_action(*_args, **_kwargs):
    build_dir = env.subst("$BUILD_DIR")
    progname  = env.subst("${PROGNAME}") or "firmware"
    out_dir   = _get_out_dir()
    os.makedirs(out_dir, exist_ok=True)
    out_path  = os.path.join(out_dir, f"Infiltra-{env.subst('$PIOENV')}.bin")

    chip = _chip()
    boot, part, app = _offsets(chip)

    # Use the actual PlatformIO executable to avoid PATH issues on Windows
    pio_exe = env.subst("$PIOEXE") or "platformio"

    cmd = (
        f'"{pio_exe}" pkg exec -p "tool-esptoolpy" -- esptool.py '
        f'--chip {chip} '
        f'merge_bin --output "{out_path}" '
        f'{boot} "{build_dir}/bootloader.bin" '
        f'{part} "{build_dir}/partitions.bin" '
        f'{app} "{build_dir}/{progname}.bin"'
    )

    print(f"[merge_bin] → {cmd}")
    return env.Execute(cmd)

merge_target = env.AddCustomTarget(
    name="merge_bin",
    dependencies=[
        "$BUILD_DIR/bootloader.bin",
        "$BUILD_DIR/partitions.bin",
        "$BUILD_DIR/${PROGNAME}.bin",
    ],
    actions=[_merge_action],
    title="Merge Firmware BIN",
    description="Create merged BIN at configured merge_out_dir (defaults to ./files)",
)
AlwaysBuild(merge_target)

# Still run after every successful build of the app binary
env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", _merge_action)

# Optional helper target (unchanged)
env.AddCustomTarget(
    name="upload_nobuild",
    dependencies=None,
    actions=["platformio run -t upload -t nobuild -e ${PIOENV}"],
    title="Upload Nobuild",
    description="Runs pio upload without building new firmware",
)
