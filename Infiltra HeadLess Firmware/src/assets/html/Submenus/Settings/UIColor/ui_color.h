#ifndef ASSETS_HTML_UI_COLOR_H
#define ASSETS_HTML_UI_COLOR_H

const char UI_COLOR_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>UI Color | Infiltra Headless</title>
    <link rel="stylesheet" href="../settings_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>UI COLOR</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>5 THEMES</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="#" class="back-button" onclick="goBack(); return false;">← Back to Settings</a>

    <div class="main">
        <div class="page-title">
            <h1>UI Color</h1>
        </div>
        
        <div class="settings-grid">
            <div class="settings-card" onclick="executeAction('original')" style="border-color: #ffffff;">
                <span class="card-emoji">🔵</span>
                <h3 class="card-title">Original</h3>
            </div>

            <div class="settings-card" onclick="executeAction('matrix')" style="border-color: #00ff00;">
                <span class="card-emoji">🟢</span>
                <h3 class="card-title">Matrix</h3>
            </div>

            <div class="settings-card" onclick="executeAction('cyberpunk')" style="border-color: #ff00ff;">
                <span class="card-emoji">🟣</span>
                <h3 class="card-title">Cyberpunk</h3>
            </div>

            <div class="settings-card" onclick="executeAction('electric')" style="border-color: #ffff00;">
                <span class="card-emoji">🟡</span>
                <h3 class="card-title">Electric</h3>
            </div>

            <div class="settings-card" onclick="executeAction('sunset')" style="border-color: #ff8000;">
                <span class="card-emoji">🟠</span>
                <h3 class="card-title">Sunset</h3>
            </div>
        </div>
    </div>
    
    <script>
        function goBack() {
            window.history.back();
        }

        function executeAction(theme) {
            console.log('UI Color theme selected:', theme);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            
            const root = document.documentElement;
            
            switch(theme) {
                case 'original':
                    root.style.setProperty('--neon-blue', '#38b6ff');
                    root.style.setProperty('--neon-green', '#00ff9d');
                    root.style.setProperty('--neon-red', '#ff3864');
                    break;
                case 'matrix':
                    root.style.setProperty('--neon-blue', '#00ff00');
                    root.style.setProperty('--neon-green', '#00ff9d');
                    root.style.setProperty('--neon-red', '#ffff00');
                    break;
                case 'cyberpunk':
                    root.style.setProperty('--neon-blue', '#ff00ff');
                    root.style.setProperty('--neon-green', '#00ffff');
                    root.style.setProperty('--neon-red', '#ff0080');
                    break;
                case 'electric':
                    root.style.setProperty('--neon-blue', '#ffff00');
                    root.style.setProperty('--neon-green', '#00ff00');
                    root.style.setProperty('--neon-red', '#0080ff');
                    break;
                case 'sunset':
                    root.style.setProperty('--neon-blue', '#ff8000');
                    root.style.setProperty('--neon-green', '#ff4000');
                    root.style.setProperty('--neon-red', '#ff0000');
                    break;
            }
            
            
            showAppliedMessage(theme);
        }

        function showAppliedMessage(theme) {
            const message = document.createElement('div');
            message.style.position = 'fixed';
            message.style.top = '50%';
            message.style.left = '50%';
            message.style.transform = 'translate(-50%, -50%)';
            message.style.background = 'rgba(0, 0, 0, 0.8)';
            message.style.color = 'var(--neon-blue)';
            message.style.padding = '20px';
            message.style.borderRadius = '8px';
            message.style.border = '2px solid var(--neon-blue)';
            message.style.zIndex = '1000';
            message.style.fontFamily = 'Orbitron, sans-serif';
            message.style.fontSize = '1.2rem';
            message.style.textAlign = 'center';
            message.innerHTML = `${theme.toUpperCase()} THEME<br>APPLIED!`;
            
            document.body.appendChild(message);
            
            setTimeout(() => {
                message.remove();
            }, 2000);
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
