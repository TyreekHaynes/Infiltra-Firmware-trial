from ...Core.APSetup import setup_access_point

def run_cli():
    print("=== Infiltra Raspberry Pi AP Setup ===")
    ssid = input("Enter SSID [Infiltra-Raspi-node]: ") or "Infiltra-Raspi-node"
    password = input("Enter Password [Infiltra1234]: ") or "Infiltra1234"
    iface = input("Enter WiFi Interface [wlan0]: ") or "wlan0"
    setup_access_point(ssid, password, iface)
