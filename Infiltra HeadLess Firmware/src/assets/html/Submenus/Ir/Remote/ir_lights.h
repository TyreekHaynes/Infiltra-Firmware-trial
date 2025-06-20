#ifndef ASSETS_HTML_IR_LIGHTS_H
#define ASSETS_HTML_IR_LIGHTS_H

const char IR_LIGHTS_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IR Lights | Infiltra Headless</title>
    <link rel="stylesheet" href="../ir_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>IR LIGHTS</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>5 BRANDS</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="ir_remote_categories.html" class="back-button">← Back to Categories</a>

    <div class="main">
        <div class="page-title">
            <h1>Lights</h1>
        </div>
        
        <div class="ir-grid">
            <div class="ir-card" onclick="executeAction('philips-hue')">
                <span class="card-emoji">💡</span>
                <h3 class="card-title">Philips Hue</h3>
            </div>

            <div class="ir-card" onclick="executeAction('lifx-lights')">
                <span class="card-emoji">💡</span>
                <h3 class="card-title">LIFX Lights</h3>
            </div>

            <div class="ir-card" onclick="executeAction('nanoleaf-lights')">
                <span class="card-emoji">💡</span>
                <h3 class="card-title">Nanoleaf Lights</h3>
            </div>

            <div class="ir-card" onclick="executeAction('govee-lights')">
                <span class="card-emoji">💡</span>
                <h3 class="card-title">Govee Lights</h3>
            </div>

            <div class="ir-card" onclick="executeAction('techlight-lights')">
                <span class="card-emoji">💡</span>
                <h3 class="card-title">TechLight</h3>
            </div>
        </div>
    </div>
    
    <script>
        function executeAction(action) {
            console.log('Light action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            
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
