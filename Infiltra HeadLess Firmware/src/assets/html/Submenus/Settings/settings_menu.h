#ifndef ASSETS_HTML_SETTINGS_MENU_H
#define ASSETS_HTML_SETTINGS_MENU_H

const char SETTINGS_MENU_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Settings | Infiltra Headless</title>
    <link rel="stylesheet" href="settings_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>SETTINGS</span>
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

    <a href="/" class="back-button" onclick="goBack(); return false;">← Back to Main</a>

    <div class="main">
        <div class="page-title">
            <h1>Settings</h1>
        </div>
        
        <div class="settings-grid">
            <div class="settings-card" onclick="executeAction('ui-color')">
                <span class="card-emoji">🎨</span>
                <h3 class="card-title">UI Color</h3>
            </div>

            <div class="settings-card" onclick="executeAction('time')">
                <span class="card-emoji">⏰</span>
                <h3 class="card-title">Time</h3>
            </div>

            <div class="settings-card" onclick="executeAction('creds')">
                <span class="card-emoji">👥</span>
                <h3 class="card-title">Creds</h3>
            </div>
        </div>
    </div>
    
    <script>
        function goBack() {
            window.history.back();
        }

        function executeAction(action) {
            console.log('Settings action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            switch(action) {
                case 'ui-color':
                    window.location.href = 'UIColor/ui_color.html';
                    break;
                case 'time':
                    console.log('Time settings selected');
                    break;
                case 'creds':
                    console.log('Credits selected');
                    break;
            }
        }

        document.addEventListener('DOMContentLoaded', function() {
            const cards = document.querySelectorAll('.settings-card');
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
