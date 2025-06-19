#ifndef ASSETS_HTML_WIFI_MENU_H
#define ASSETS_HTML_WIFI_MENU_H

const char WIFI_MENU_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>WiFi | Infiltra Headless</title>
    <link rel="stylesheet" href="wifi_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>WIFI</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>5 TOOLS ACTIVE</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="/" class="back-button">← Back to Main</a>

    <div class="main">
        <div class="page-title">
            <h1>WiFi</h1>
        </div>
        
        <div class="wifi-grid">
            <div class="wifi-card" onclick="executeAction('scan-networks')">
                <span class="card-emoji">📡</span>
                <h3 class="card-title">Scan Networks</h3>
            </div>

            <div class="wifi-card" onclick="executeAction('evil-portal')">
                <span class="card-emoji">🕳️</span>
                <h3 class="card-title">Evil Portal</h3>
            </div>

            <div class="wifi-card" onclick="executeAction('raw-sniffer')">
                <span class="card-emoji">🔍</span>
                <h3 class="card-title">Raw Sniffer</h3>
            </div>

            <div class="wifi-card" onclick="executeAction('packet-sniffer')">
                <span class="card-emoji">📦</span>
                <h3 class="card-title">Packet Sniffer</h3>
            </div>

            <div class="wifi-card" onclick="executeAction('deauth-wifi')">
                <span class="card-emoji">⚡</span>
                <h3 class="card-title">Deauth WiFi</h3>
            </div>
        </div>
    </div>
    
    <script>
        function executeAction(action) {
            console.log('WiFi action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            
        }

        document.addEventListener('DOMContentLoaded', function() {
            const cards = document.querySelectorAll('.wifi-card');
            cards.forEach((card, index) => {
                card.style.opacity = '0';
                card.style.transform = 'translateY(30px)';
                
                setTimeout(() => {
                    card.style.transition = 'all 0.6s ease';
                    card.style.opacity = '1';
                    card.style.transform = 'translateY(0)';
                }, index * 100);
            });
        });
    </script>
</body>
</html>)rawliteral";

#endif
