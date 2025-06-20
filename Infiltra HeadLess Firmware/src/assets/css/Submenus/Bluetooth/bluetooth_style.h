#ifndef ASSETS_HTML_BLUETOOTH_MENU_H
#define ASSETS_HTML_BLUETOOTH_MENU_H

const char BLUETOOTH_MENU_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bluetooth | Infiltra Headless</title>
    <link rel="stylesheet" href="bluetooth_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>BLUETOOTH</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>8 TOOLS ACTIVE</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="/" class="back-button" onclick="goBack(); return false;">← Back to Main</a>

    <div class="main">
        <div class="page-title">
            <h1>Bluetooth</h1>
        </div>
        
        <div class="bluetooth-grid">
            <div class="bluetooth-card" onclick="executeAction('ios-spam')">
                <span class="card-emoji">🍎</span>
                <h3 class="card-title">iOS Spam</h3>
            </div>

            <div class="bluetooth-card" onclick="executeAction('android-spam')">
                <span class="card-emoji">🤖</span>
                <h3 class="card-title">Android Spam</h3>
            </div>

            <div class="bluetooth-card" onclick="executeAction('google-spam')">
                <span class="card-emoji">🔍</span>
                <h3 class="card-title">Google Spam</h3>
            </div>

            <div class="bluetooth-card" onclick="executeAction('windows-spam')">
                <span class="card-emoji">🪟</span>
                <h3 class="card-title">Windows Spam</h3>
            </div>

            <div class="bluetooth-card" onclick="executeAction('samsung-spam')">
                <span class="card-emoji">📱</span>
                <h3 class="card-title">Samsung Spam</h3>
            </div>

            <div class="bluetooth-card" onclick="executeAction('ble-controller')">
                <span class="card-emoji">🎮</span>
                <h3 class="card-title">BLE Controller</h3>
            </div>

            <div class="bluetooth-card" onclick="executeAction('ble-scanner')">
                <span class="card-emoji">📡</span>
                <h3 class="card-title">BLE Scanner</h3>
            </div>

            <div class="bluetooth-card" onclick="executeAction('card-skim')">
                <span class="card-emoji">💳</span>
                <h3 class="card-title">Card Skim</h3>
            </div>
        </div>
    </div>
    
    <script>
        function goBack() {
            window.history.back();
        }

        function executeAction(action) {
            console.log('Bluetooth action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            
        }

        document.addEventListener('DOMContentLoaded', function() {
            const cards = document.querySelectorAll('.bluetooth-card');
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

