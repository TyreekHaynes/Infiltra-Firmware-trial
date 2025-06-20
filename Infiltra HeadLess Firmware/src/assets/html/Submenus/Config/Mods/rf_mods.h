#ifndef ASSETS_HTML_RF_MODS_H
#define ASSETS_HTML_RF_MODS_H

const char RF_MODS_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RF Mods | Infiltra Headless</title>
    <link rel="stylesheet" href="../config_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>RF MODS</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>3 OPTIONS</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="#" class="back-button" onclick="goBack(); return false;">← Back to Config</a>

    <div class="main">
        <div class="page-title">
            <h1>RF Mods</h1>
        </div>
        
        <div class="config-grid">
            <div class="config-card" onclick="executeAction('m5-mod-tr')">
                <span class="card-emoji">📡</span>
                <h3 class="card-title">M5 Mod T/R</h3>
            </div>

            <div class="config-card" onclick="executeAction('g26')">
                <span class="card-emoji">🔧</span>
                <h3 class="card-title">G26</h3>
            </div>

            <div class="config-card" onclick="executeAction('cc1101')">
                <span class="card-emoji">📻</span>
                <h3 class="card-title">CC1101</h3>
            </div>
        </div>
    </div>
    
    <script>
        function goBack() {
            window.history.back();
        }

        function executeAction(action) {
            console.log('RF Mods action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            switch(action) {
                case 'm5-mod-tr':
                    console.log('M5 Mod T/R selected');
                    break;
                case 'g26':
                    console.log('G26 selected');
                    break;
                case 'cc1101':
                    console.log('CC1101 selected');
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
