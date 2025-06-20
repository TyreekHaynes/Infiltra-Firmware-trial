#ifndef ASSETS_HTML_LANDING_PAGE_H
#define ASSETS_HTML_LANDING_PAGE_H

const char LANDING_PAGE_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Infiltra Headless | Advanced Penetration Toolkit</title>
    <link rel="stylesheet" href="style.css">
    <link rel="preload" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css" as="style" onload="this.onload=null;this.rel='stylesheet'">
    <noscript><link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css"></noscript>
    <style>
        /* Fallback icons using Unicode symbols */
        .module-icon.fallback-wifi::before { content: "📶"; }
        .module-icon.fallback-bluetooth::before { content: "🔵"; }
        .module-icon.fallback-rfid::before { content: "💳"; }
        .module-icon.fallback-rf::before { content: "📡"; }
        .module-icon.fallback-ir::before { content: "🔴"; }
        .module-icon.fallback-usb::before { content: "🔌"; }
        .module-icon.fallback-config::before { content: "⚙️"; }
        .module-icon.fallback-settings::before { content: "🔧"; }
        
        .module-icon.fallback-wifi::before,
        .module-icon.fallback-bluetooth::before,
        .module-icon.fallback-rfid::before,
        .module-icon.fallback-rf::before,
        .module-icon.fallback-ir::before,
        .module-icon.fallback-usb::before,
        .module-icon.fallback-config::before,
        .module-icon.fallback-settings::before {
            font-size: 2.5rem;
            line-height: 80px;
        }
    </style>
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>SYSTEM ACTIVE</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>NETWORK SECURE</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-green);"></div>
                <span>MEM: %</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <div class="main">
        <div class="header">
            <div class="glitch-container">
                <h1 class="title">Infiltra Headless</h1>
            </div>
            <p class="tagline typing">// ADVANCED PENETRATION TOOLKIT //</p>
            <p class="subtitle">A powerful suite of hardware and software tools designed for security professionals to test and assess vulnerabilities across various interfaces and protocols.</p>
        </div>
        
        <div class="modules-container">
            <div class="modules-grid">
                <div class="module" onclick="window.location.href='/wifi'">
                    <div class="module-inner">
                        <div class="module-icon fallback-wifi">
                            <i class="fas fa-wifi"></i>
                        </div>
                        <h2 class="module-title">WiFi</h2>
                        <div class="module-stats">
                            <div class="module-stat">
                                <i class="fas fa-shield-alt">🛡️</i>
                                <span>WPA/WPA2/WPS</span>
                            </div>
                        </div>
                    </div>
                    <div class="data-line" style="right: 0; width: 80px;"></div>
                </div>

                <div class="module" onclick="window.location.href='/bluetooth'">
                    <div class="module-inner">
                        <div class="module-icon fallback-bluetooth">
                            <i class="fab fa-bluetooth-b"></i>
                        </div>
                        <h2 class="module-title">Bluetooth</h2>
                        <div class="module-stats">
                            <div class="module-stat">
                                <i class="fas fa-cog">⚙️</i>
                                <span>BLE 5.0</span>
                            </div>
                        </div>
                    </div>
                    <div class="data-line" style="right: 20px; width: 60px;"></div>
                </div>

                <div class="module" onclick="window.location.href='/rfid'">
                    <div class="module-inner">
                        <div class="module-icon fallback-rfid">
                            <i class="fas fa-id-card"></i>
                        </div>
                        <h2 class="module-title">RFID</h2>
                        <div class="module-stats">
                            <div class="module-stat">
                                <i class="fas fa-tag">🏷️</i>
                                <span>125KHz/13.56MHz</span>
                            </div>
                            <div class="module-stat">
                                <i class="fas fa-clone">📋</i>
                                <span>Emulation Ready</span>
                            </div>
                        </div>
                    </div>
                    <div class="data-line" style="right: 10px; width: 70px;"></div>
                </div>

                <div class="module" onclick="window.location.href='/rf'">
                    <div class="module-inner">
                        <div class="module-icon fallback-rf">
                            <i class="fas fa-broadcast-tower"></i>
                        </div>
                        <h2 class="module-title">RF</h2>
                        <div class="module-stats">
                            <div class="module-stat">
                                <i class="fas fa-wave-square">〰️</i>
                                <span>433/868/915MHz</span>
                            </div>
                            <div class="module-stat">
                                <i class="fas fa-bolt">⚡</i>
                                <span>SDR Compatible</span>
                            </div>
                        </div>
                    </div>
                    <div class="data-line" style="right: 5px; width: 75px;"></div>
                </div>

                <div class="module" onclick="window.location.href='/ir'">
                    <div class="module-inner">
                        <div class="module-icon fallback-ir">
                            <i class="fas fa-satellite-dish"></i>
                        </div>
                        <h2 class="module-title">IR</h2>
                        <div class="module-stats">
                            <div class="module-stat">
                                <i class="fas fa-sync">🔄</i>
                                <span>Auto-Sequence</span>
                            </div>
                        </div>
                    </div>
                    <div class="data-line" style="right: 15px; width: 65px;"></div>
                </div>

                <div class="module">
                    <div class="module-inner">
                        <div class="module-icon fallback-usb">
                            <i class="fas fa-usb"></i>
                        </div>
                        <h2 class="module-title">Bad USB</h2>
                        <div class="module-stats">
                            <div class="module-stat">
                                <i class="fas fa-keyboard">⌨️</i>
                                <span>HID Emulation</span>
                            </div>
                        </div>
                    </div>
                    <div class="data-line" style="right: 25px; width: 55px;"></div>
                </div>

                <div class="module">
                    <div class="module-inner">
                        <div class="module-icon fallback-config">
                            <i class="fas fa-cogs"></i>
                        </div>
                        <h2 class="module-title">Config</h2>
                        <div class="module-stats">
                            <div class="module-stat">
                                <i class="fas fa-microchip">🔧</i>
                                <span>GPIO Controls</span>
                            </div>
                            <div class="module-stat">
                                <i class="fas fa-plug">🔌</i>
                                <span>Interfaces</span>
                            </div>
                        </div>
                    </div>
                    <div class="data-line" style="right: 30px; width: 50px;"></div>
                </div>

                <div class="module">
                    <div class="module-inner">
                        <div class="module-icon fallback-settings">
                            <i class="fas fa-sliders-h"></i>
                        </div>
                        <h2 class="module-title">Settings</h2>
                        <div class="module-stats">
                            <div class="module-stat">
                                <i class="fas fa-user-shield">🛡️</i>
                                <span>Security Controls</span>
                            </div>
                            <div class="module-stat">
                                <i class="fas fa-database">💾</i>
                                <span>Logging</span>
                            </div>
                        </div>
                    </div>
                    <div class="data-line" style="right: 35px; width: 45px;"></div>
                </div>
            </div>
        </div>

        <div class="footer">
            <div class="footer-top">
                <div class="stats-container">
                    <div class="stat-item">
                        <span class="stat-label">System Status</span>
                        <span class="stat-value">ACTIVE</span>
                    </div>
                    <div class="stat-item">
                        <span class="stat-label">Memory</span>
                        <span class="stat-value">67%</span>
                    </div>
                    <div class="stat-item">
                        <span class="stat-label">Network</span>
                        <span class="stat-value">SECURE</span>
                    </div>
                    <div class="stat-item">
                        <span class="stat-label">Version</span>
                        <span class="stat-value">1.0.5</span>
                    </div>
                </div>
            </div>
            <div class="footer-bottom">
                <div>Infiltra Network © 2023 | Designed for security professionals | Use responsibly</div>
                <div class="footer-links">
                    <a href="#" class="footer-link">Documentation</a>
                    <a href="#" class="footer-link">Updates</a>
                    <a href="#" class="footer-link">Support</a>
                </div>
            </div>
        </div>
    </div>
    
    <script>
        document.addEventListener('DOMContentLoaded', function() {
            // Check if Font Awesome is loaded, if not show fallback icons
            setTimeout(function() {
                const testIcon = document.createElement('i');
                testIcon.className = 'fas fa-wifi';
                testIcon.style.position = 'absolute';
                testIcon.style.left = '-9999px';
                document.body.appendChild(testIcon);
                
                const computedStyle = window.getComputedStyle(testIcon, ':before');
                const content = computedStyle.getPropertyValue('content');
                
                if (!content || content === 'none' || content === '""') {
                    // Font Awesome not loaded, show fallback
                    document.querySelectorAll('.module-icon i').forEach(icon => {
                        icon.style.display = 'none';
                    });
                    document.querySelectorAll('.module-icon').forEach(icon => {
                        icon.style.fontSize = '2.5rem';
                    });
                }
                
                document.body.removeChild(testIcon);
            }, 100);
            
            const tagline = document.querySelector('.tagline');
            const taglineText = tagline.textContent;
            tagline.textContent = '';
            tagline.classList.add('typing');
            
            let i = 0;
            function typeWriter() {
                if (i < taglineText.length) {
                    tagline.textContent += taglineText.charAt(i);
                    i++;
                    setTimeout(typeWriter, 50);
                } else {
                    setTimeout(() => {
                        tagline.classList.remove('typing');
                    }, 1000);
                }
            }
            
            setTimeout(typeWriter, 1000);
            
            const modules = document.querySelectorAll('.module');
            
            modules.forEach((module, index) => {
                const dataLine = module.querySelector('.data-line');
                dataLine.style.animationDelay = (index * 0.2) + 's';
                
                module.addEventListener('click', function() {
                    const moduleName = this.querySelector('.module-title').textContent;
                    console.log(`Activating ${moduleName} module`);
                    
                    this.style.transform = 'scale(0.95)';
                    setTimeout(() => {
                        this.style.transform = '';
                    }, 150);
                    
                    const pulse = document.createElement('div');
                    pulse.className = 'pulse-effect';
                    pulse.style.position = 'absolute';
                    pulse.style.top = '0';
                    pulse.style.left = '0';
                    pulse.style.right = '0';
                    pulse.style.bottom = '0';
                    pulse.style.backgroundColor = 'rgba(56, 182, 255, 0.1)';
                    pulse.style.zIndex = '0';
                    pulse.style.opacity = '1';
                    pulse.style.borderRadius = '8px';
                    pulse.style.transition = 'all 0.5s ease';
                    
                    this.appendChild(pulse);
                    
                    setTimeout(() => {
                        pulse.style.opacity = '0';
                        pulse.style.transform = 'scale(1.2)';
                        setTimeout(() => {
                            pulse.remove();
                        }, 500);
                    }, 10);
                });
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
            
            modules.forEach(module => {
                module.addEventListener('mousemove', function(e) {
                    const rect = this.getBoundingClientRect();
                    const x = e.clientX - rect.left;
                    const y = e.clientY - rect.top;
                    
                    const xRotation = 10 * ((y - rect.height / 2) / rect.height);
                    const yRotation = -10 * ((x - rect.width / 2) / rect.width);
                    
                    this.style.transform = `perspective(1000px) rotateX(${xRotation}deg) rotateY(${yRotation}deg) scale3d(1.02, 1.02, 1.02)`;
                });
                
                module.addEventListener('mouseout', function() {
                    this.style.transform = 'perspective(1000px) rotateX(0) rotateY(0) scale3d(1, 1, 1)';
                });
            });
        });
    </script>
</body>
</html>)rawliteral";

#endif
