#ifndef ASSETS_HTML_CONFIG_MENU_H
#define ASSETS_HTML_CONFIG_MENU_H

const char CONFIG_MENU_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Config | Infiltra Headless</title>
    <link rel="stylesheet" href="config_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>CONFIG</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>3 MODULES</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="/" class="back-button" onclick="goBack(); return false;">← Back to Main</a>

    <div class="main">
        <div class="page-title">
            <h1>Config</h1>
        </div>
        
        <div class="config-grid">
            <div class="config-card" onclick="executeAction('ir-mods')">
                <span class="card-emoji">🔴</span>
                <h3 class="card-title">IR Mods</h3>
            </div>

            <div class="config-card" onclick="executeAction('rf-mods')">
                <span class="card-emoji">📡</span>
                <h3 class="card-title">RF Mods</h3>
            </div>

            <div class="config-card" onclick="executeAction('rfid-mods')">
                <span class="card-emoji">💳</span>
                <h3 class="card-title">RFID Mods</h3>
            </div>
        </div>
    </div>
    
    <script>
        function goBack() {
            window.history.back();
        }

        function executeAction(action) {
            console.log('Config action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            switch(action) {
                case 'ir-mods':
                    window.location.href = 'Mods/ir_mods.html';
                    break;
                case 'rf-mods':
                    window.location.href = 'Mods/rf_mods.html';
                    break;
                case 'rfid-mods':
                    console.log('RFID Mods selected - No options available');
                    break;
            }
        }

        document.addEventListener('DOMContentLoaded', function() {
            const cards = document.querySelectorAll('.config-card');
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
