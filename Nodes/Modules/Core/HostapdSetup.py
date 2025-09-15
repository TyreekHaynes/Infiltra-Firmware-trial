import subprocess
from pathlib import Path

def setup_hostapd_ap(ssid, password, iface):
    hostapd_conf = f"""
interface={iface}
driver=nl80211
ssid={ssid}
hw_mode=g
channel=6
wpa=2
wpa_passphrase={password}
wpa_key_mgmt=WPA-PSK
rsn_pairwise=CCMP
"""
    Path("/etc/hostapd/hostapd.conf").write_text(hostapd_conf)
    subprocess.run(["sudo", "systemctl", "enable", "hostapd"])
    subprocess.run(["sudo", "systemctl", "start", "hostapd"])
    print(f"[+] AP '{ssid}' is now active via hostapd.")
