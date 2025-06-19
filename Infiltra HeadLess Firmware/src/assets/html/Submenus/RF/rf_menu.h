#ifndef ASSETS_HTML_RF_MENU_H
#define ASSETS_HTML_RF_MENU_H

const char RF_MENU_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RF | Infiltra Headless</title>
    <link rel="stylesheet" href="rf_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>RF</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>4 TOOLS ACTIVE</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="/" class="back-button">← Back to Main</a>

    <div class="main">
        <div class="page-title">
            <h1>RF</h1>
        </div>
        
        <div class="rf-grid">
            <div class="rf-card" onclick="executeAction('rf-visualizer')">
                <span class="card-emoji">📊</span>
                <h3 class="card-title">RF Visualizer</h3>
            </div>

            <div class="rf-card" onclick="executeAction('jammer')">
                <span class="card-emoji">📡</span>
                <h3 class="card-title">Jammer</h3>
            </div>

            <div class="rf-card" onclick="executeAction('custom-fq')">
                <span class="card-emoji">⚙️</span>
                <h3 class="card-title">Custom FQ</h3>
            </div>

            <div class="rf-card" onclick="executeAction('custom-subghz')">
                <span class="card-emoji">📻</span>
                <h3 class="card-title">Custom SubGHz</h3>
            </div>
        </div>
    </div>
    
    <script>
        function executeAction(action) {
            console.log('RF action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            
        }

        document.addEventListener('DOMContentLoaded', function() {
            const cards = document.querySelectorAll('.rf-card');
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
