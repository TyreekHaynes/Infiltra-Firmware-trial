#ifndef ASSETS_HTML_IR_TVS_H
#define ASSETS_HTML_IR_TVS_H

const char IR_TVS_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IR TVs | Infiltra Headless</title>
    <link rel="stylesheet" href="../ir_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>IR TVS</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>6 BRANDS</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="ir_remote_categories.html" class="back-button">← Back to Categories</a>

    <div class="main">
        <div class="page-title">
            <h1>TVs</h1>
        </div>
        
        <div class="ir-grid">
            <div class="ir-card" onclick="executeAction('samsung-tv')">
                <span class="card-emoji">📺</span>
                <h3 class="card-title">Samsung TV</h3>
            </div>

            <div class="ir-card" onclick="executeAction('lg-tv')">
                <span class="card-emoji">📺</span>
                <h3 class="card-title">LG TV</h3>
            </div>

            <div class="ir-card" onclick="executeAction('sony-tv')">
                <span class="card-emoji">📺</span>
                <h3 class="card-title">Sony TV</h3>
            </div>

            <div class="ir-card" onclick="executeAction('hisense-tv')">
                <span class="card-emoji">📺</span>
                <h3 class="card-title">Hisense TV</h3>
            </div>

            <div class="ir-card" onclick="executeAction('philips-tv')">
                <span class="card-emoji">📺</span>
                <h3 class="card-title">Philips TV</h3>
            </div>

            <div class="ir-card" onclick="executeAction('panasonic-tv')">
                <span class="card-emoji">📺</span>
                <h3 class="card-title">Panasonic TV</h3>
            </div>
        </div>
    </div>
    
    <script>
        function executeAction(action) {
            console.log('TV action:', action);
            
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
