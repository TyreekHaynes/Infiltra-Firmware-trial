import subprocess
from .NetworkManagerSetup import setup_nm_ap
from .HostapdSetup import setup_hostapd_ap

def setup_access_point(ssid="Infiltra-Raspi-node", password="Infiltra1234", iface="wlan0"):
    """Detects available method and sets up AP."""
    if subprocess.call(["which", "nmcli"], stdout=subprocess.DEVNULL) == 0:
        print("[*] NetworkManager detected, using nmcli...")
        setup_nm_ap(ssid, password, iface)
    else:
        print("[*] Falling back to hostapd + dnsmasq...")
        setup_hostapd_ap(ssid, password, iface)
