#ifndef ASSETS_HTML_IR_MENU_H
#define ASSETS_HTML_IR_MENU_H

const char IR_MENU_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IR | Infiltra Headless</title>
    <link rel="stylesheet" href="ir_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>IR</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>30+ DEVICES</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="/" class="back-button" onclick="goBack(); return false;">← Back to Main</a>

    <div class="main">
        <div class="page-title">
            <h1>IR</h1>
        </div>
        
        <div class="ir-grid">
            <div class="ir-card" onclick="executeAction('ir-remote')">
                <span class="card-emoji">📱</span>
                <h3 class="card-title">IR Remote</h3>
            </div>

            <div class="ir-card" onclick="executeAction('ir-play')">
                <span class="card-emoji">▶️</span>
                <h3 class="card-title">IR Play</h3>
            </div>

            <div class="ir-card" onclick="executeAction('custom-ir')">
                <span class="card-emoji">⚙️</span>
                <h3 class="card-title">Custom IR</h3>
            </div>
        </div>
    </div>
    
    <script>
        function goBack() {
            window.history.back();
        }

        function executeAction(action) {
            console.log('IR action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            switch(action) {
                case 'ir-remote':
                    window.location.href = 'Remote/ir_remote_categories.html';
                    break;
                case 'ir-play':
                    console.log('IR Play selected');
                    break;
                case 'custom-ir':
                    console.log('Custom IR selected');
                    break;
            }
        }

        document.addEventListener('DOMContentLoaded', function() {
            const cards = document.querySelectorAll('.ir-card');
            cards.forEach((card, index) => {
                card.style.opacity = '0';
                card.style.transform = 'translateY(30px)';
                
                setTimeout(() => {
                    card.style.transition = 'all 0.6s ease';
                    card.style.opacity = '1';
                    card.style.transform = 'translateY(0)';
                }, index * 50);
            });
        });
    </script>
</body>
</html>)rawliteral";

#endif
