#ifndef ASSETS_HTML_IR_REMOTE_CATEGORIES_H
#define ASSETS_HTML_IR_REMOTE_CATEGORIES_H

const char IR_REMOTE_CATEGORIES_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IR Remote | Infiltra Headless</title>
    <link rel="stylesheet" href="../ir_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>IR REMOTE</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>5 CATEGORIES</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="../ir_menu.html" class="back-button">← Back to IR</a>

    <div class="main">
        <div class="page-title">
            <h1>IR Remote</h1>
        </div>
        
        <div class="ir-grid">
            <div class="ir-card" onclick="executeAction('tvs')">
                <span class="card-emoji">📺</span>
                <h3 class="card-title">TVs</h3>
            </div>

            <div class="ir-card" onclick="executeAction('projectors')">
                <span class="card-emoji">📽️</span>
                <h3 class="card-title">Projectors</h3>
            </div>

            <div class="ir-card" onclick="executeAction('lights')">
                <span class="card-emoji">💡</span>
                <h3 class="card-title">Lights</h3>
            </div>

            <div class="ir-card" onclick="executeAction('whiteboards')">
                <span class="card-emoji">📋</span>
                <h3 class="card-title">Whiteboards</h3>
            </div>

            <div class="ir-card" onclick="executeAction('displays')">
                <span class="card-emoji">🖥️</span>
                <h3 class="card-title">Displays</h3>
            </div>
        </div>
    </div>
    
    <script>
        function executeAction(action) {
            console.log('IR Remote category:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            switch(action) {
                case 'tvs':
                    window.location.href = 'ir_tvs.html';
                    break;
                case 'projectors':
                    window.location.href = 'ir_projectors.html';
                    break;
                case 'lights':
                    window.location.href = 'ir_lights.html';
                    break;
                case 'whiteboards':
                    console.log('Whiteboards selected');
                    break;
                case 'displays':
                    console.log('Displays selected');
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
                }, index * 100);
            });
        });
    </script>
</body>
</html>)rawliteral";

#endif
