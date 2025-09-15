import subprocess

def setup_nm_ap(ssid, password, iface):
    subprocess.run(["sudo", "nmcli", "connection", "delete", "infiltra-ap"], stderr=subprocess.DEVNULL)
    subprocess.run([
        "sudo", "nmcli", "connection", "add",
        "type", "wifi", "ifname", iface, "mode", "ap",
        "con-name", "infiltra-ap", "ssid", ssid
    ])
    subprocess.run([
        "sudo", "nmcli", "connection", "modify", "infiltra-ap",
        "802-11-wireless.mode", "ap",
        "802-11-wireless.band", "bg",
        "ipv4.method", "shared",
        "wifi-sec.key-mgmt", "wpa-psk",
        "wifi-sec.psk", password
    ])
    subprocess.run(["sudo", "nmcli", "connection", "up", "infiltra-ap"])
    print(f"[+] AP '{ssid}' is now active via NetworkManager.")
