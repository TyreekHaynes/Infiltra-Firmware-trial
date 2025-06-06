#ifndef ASSETS_HTML_SETUP_PAGE_H
#define ASSETS_HTML_SETUP_PAGE_H

const char SETUP_PAGE_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Infiltra Setup | Initial Configuration</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="setup_style.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
</head>
<body>
    <div class="noise"></div>
    
    <div class="background">
        <div class="grid"></div>
    </div>

    <div class="main">
        <div class="setup-logo">
            <i class="fas fa-shield-alt"></i>
        </div>
        
        <div class="setup-container">
            <h1 class="setup-title">Infiltra Initial Setup</h1>
            
            <form action="/saveconfig" method="POST">
                <div class="setup-section">
                    <h2 class="setup-section-title">Network Configuration</h2>
                    
                    <div class="form-group">
                        <label class="form-label" for="ssid">Access Point Name (SSID)</label>
                        <input type="text" id="ssid" name="ssid" class="form-input" value="infiltra" required>
                        <div class="form-help">This will be the name of your WiFi network</div>
                    </div>
                    
                    <div class="form-group">
                        <div class="form-check">
                            <input type="checkbox" id="usePassword" name="usePassword" class="form-check-input">
                            <label class="form-label" for="usePassword">Secure with Password</label>
                        </div>
                    </div>
                    
                    <div class="form-group password-fields" style="display: none;">
                        <label class="form-label" for="password">Password (min 8 characters)</label>
                        <div class="password-toggle">
                            <input type="password" id="password" name="password" class="form-input" minlength="8">
                            <i class="fas fa-eye" id="togglePassword"></i>
                        </div>
                        <div class="password-strength">
                            <div class="password-strength-bar" id="strengthBar"></div>
                        </div>
                        <div class="form-help">Strong password recommended for security</div>
                    </div>
                </div>
                
                <div class="setup-section">
                    <h2 class="setup-section-title">IP Configuration</h2>
                    
                    <div class="form-group">
                        <div class="form-check">
                            <input type="checkbox" id="useStaticIP" name="useStaticIP" class="form-check-input">
                            <label class="form-label" for="useStaticIP">Use Custom IP Address</label>
                        </div>
                    </div>
                    
                    <div class="form-group ip-fields" style="display: none;">
                        <label class="form-label" for="ipPreset">Select IP Address</label>
                        <select id="ipPreset" name="ipPreset" class="form-select">
                            <option value="192.168.4.1">192.168.4.1 (Default)</option>
                            <option value="10.0.0.1">10.0.0.1</option>
                            <option value="172.16.0.1">172.16.0.1</option>
                            <option value="192.168.1.1">192.168.1.1</option>
                            <option value="192.168.0.1">192.168.0.1</option>
                            <option value="192.168.2.1">192.168.2.1</option>
                            <option value="192.168.100.1">192.168.100.1</option>
                            <option value="10.1.1.1">10.1.1.1</option>
                            <option value="10.10.10.1">10.10.10.1</option>
                            <option value="custom">Custom IP...</option>
                        </select>
                        <div class="form-help">Gateway will be set to the same IP address</div>
                    </div>
                    
                    <div class="form-group custom-ip-fields" style="display: none;">
                        <label class="form-label" for="customIP">Custom IP Address</label>
                        <input type="text" id="customIP" name="customIP" class="form-input" placeholder="192.168.x.x">
                        <div class="form-help">Enter a valid IPv4 address</div>
                    </div>
                    
                    <div class="form-group">
                        <label class="form-label" for="dhcpRange">DHCP IP Range</label>
                        <select id="dhcpRange" name="dhcpRange" class="form-select">
                            <option value="100">100 IPs (x.x.x.100 - x.x.x.199)</option>
                            <option value="50">50 IPs (x.x.x.100 - x.x.x.149)</option>
                            <option value="20">20 IPs (x.x.x.100 - x.x.x.119)</option>
                            <option value="10">10 IPs (x.x.x.100 - x.x.x.109)</option>
                        </select>
                        <div class="form-help">Number of IP addresses to assign to clients</div>
                    </div>
                </div>
                
                <div class="setup-section">
                    <h2 class="setup-section-title">System Preferences</h2>
                    
                    <div class="form-group">
                        <div class="form-check">
                            <input type="checkbox" id="disableBeep" name="disableBeep" class="form-check-input">
                            <label class="form-label" for="disableBeep">Disable Beep Sounds</label>
                        </div>
                        <div class="form-help">Mute the device's beep notifications</div>
                    </div>
                    
                    <div class="form-group">
                        <label class="form-label" for="displayBrightness">Display Brightness</label>
                        <input type="range" id="displayBrightness" name="displayBrightness" min="10" max="100" value="70" class="form-input">
                        <div class="form-help">Adjust screen brightness (affects battery life)</div>
                    </div>
                    
                    <div class="form-group">
                        <label class="form-label" for="sleepTimeout">Sleep Timeout</label>
                        <select id="sleepTimeout" name="sleepTimeout" class="form-select">
                            <option value="never">Never</option>
                            <option value="5">5 minutes</option>
                            <option value="10">10 minutes</option>
                            <option value="30">30 minutes</option>
                            <option value="60">1 hour</option>
                        </select>
                        <div class="form-help">Time before device enters sleep mode</div>
                    </div>
                </div>
                
                <button type="submit" class="form-submit">Save Configuration</button>
            </form>
        </div>
        
        <div class="setup-footer">
            Infiltra Setup Wizard | Version 1.0.5
        </div>
    </div>
    
    <script>
        document.addEventListener('DOMContentLoaded', function() {
            const usePasswordCheckbox = document.getElementById('usePassword');
            const passwordFields = document.querySelector('.password-fields');
            
            usePasswordCheckbox.addEventListener('change', function() {
                passwordFields.style.display = this.checked ? 'block' : 'none';
            });

            const useStaticIPCheckbox = document.getElementById('useStaticIP');
            const ipFields = document.querySelector('.ip-fields');
            
            useStaticIPCheckbox.addEventListener('change', function() {
                ipFields.style.display = this.checked ? 'block' : 'none';
            });

            const ipPresetSelect = document.getElementById('ipPreset');
            const customIPFields = document.querySelector('.custom-ip-fields');
            
            ipPresetSelect.addEventListener('change', function() {
                customIPFields.style.display = this.value === 'custom' ? 'block' : 'none';
            });
            
            const customIPInput = document.getElementById('customIP');
            customIPInput.addEventListener('blur', function() {
                const ipPattern = /^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/;
                
                if (!ipPattern.test(this.value) && this.value !== '') {
                    this.style.borderColor = 'var(--neon-red)';
                    alert('Please enter a valid IP address');
                } else {
                    this.style.borderColor = 'rgba(56, 182, 255, 0.3)';
                }
            });

            const togglePassword = document.getElementById('togglePassword');
            const passwordInput = document.getElementById('password');
            
            togglePassword.addEventListener('click', function() {
                const type = passwordInput.getAttribute('type') === 'password' ? 'text' : 'password';
                passwordInput.setAttribute('type', type);
                this.classList.toggle('fa-eye');
                this.classList.toggle('fa-eye-slash');
            });

            const strengthBar = document.getElementById('strengthBar');
            
            passwordInput.addEventListener('input', function() {
                const password = this.value;
                let strength = 0;
                
                if (password.length >= 8) strength += 1;
                if (password.match(/[A-Z]/)) strength += 1;
                if (password.match(/[0-9]/)) strength += 1;
                if (password.match(/[^A-Za-z0-9]/)) strength += 1;
                
                strengthBar.className = 'password-strength-bar';
                
                if (password.length === 0) {
                    strengthBar.style.width = '0%';
                } else if (strength <= 2) {
                    strengthBar.classList.add('strength-weak');
                } else if (strength === 3) {
                    strengthBar.classList.add('strength-medium');
                } else {
                    strengthBar.classList.add('strength-strong');
                }
            });

            const brightnessSlider = document.getElementById('displayBrightness');
            brightnessSlider.addEventListener('input', function() {
                const brightness = this.value;
                document.body.style.opacity = brightness / 100;
                setTimeout(() => {
                    document.body.style.opacity = 1;
                }, 500);
            });

            const background = document.querySelector('.background');
            for (let i = 0; i < 30; i++) {
                const bit = document.createElement('div');
                bit.className = 'data-bit';
                bit.style.position = 'absolute';
                bit.style.width = '2px';
                bit.style.height = '2px';
                bit.style.backgroundColor = 'rgba(56, 182, 255, ' + (Math.random() * 0.3 + 0.1) + ')';
                bit.style.left = Math.random() * 100 + 'vw';
                bit.style.top = Math.random() * 100 + 'vh';
                bit.style.boxShadow = '0 0 3px rgba(56, 182, 255, 0.5)';
                bit.style.animation = 'float ' + (Math.random() * 10 + 10) + 's linear infinite';
                bit.style.animationDelay = Math.random() * 10 + 's';
                
                background.appendChild(bit);
            }
            
            const style = document.createElement('style');
            style.textContent = `
                @keyframes float {
                    0% {
                        transform: translateY(0) translateX(0);
                        opacity: 0;
                    }
                    10% {
                        opacity: 1;
                    }
                    90% {
                        opacity: 1;
                    }
                    100% {
                        transform: translateY(-100vh) translateX(20px);
                        opacity: 0;
                    }
                }
            `;
            document.head.appendChild(style);
        });
    </script>
</body>
</html>)rawliteral";

#endif
