#ifndef ASSETS_HTML_RFID_MENU_H
#define ASSETS_HTML_RFID_MENU_H

const char RFID_MENU_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RFID | Infiltra Headless</title>
    <link rel="stylesheet" href="rfid_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>RFID</span>
            </div>
            <div class="status-item">
                <div class="status-dot" style="background-color: var(--neon-blue);"></div>
                <span>5 TOOLS ACTIVE</span>
            </div>
        </div>
    </nav>

    <div class="background">
        <div class="grid"></div>
    </div>

    <a href="/" class="back-button">← Back to Main</a>

    <div class="main">
        <div class="page-title">
            <h1>RFID</h1>
        </div>
        
        <div class="rfid-grid">
            <div class="rfid-card" onclick="executeAction('copy-rfid')">
                <span class="card-emoji">📋</span>
                <h3 class="card-title">Copy RFID</h3>
            </div>

            <div class="rfid-card" onclick="executeAction('scan-tags')">
                <span class="card-emoji">🔍</span>
                <h3 class="card-title">Scan Tags</h3>
            </div>

            <div class="rfid-card" onclick="executeAction('write-tags')">
                <span class="card-emoji">✏️</span>
                <h3 class="card-title">Write Tags</h3>
            </div>

            <div class="rfid-card" onclick="executeAction('erase-tag')">
                <span class="card-emoji">🗑️</span>
                <h3 class="card-title">Erase Tag</h3>
            </div>

            <div class="rfid-card" onclick="executeAction('load-file')">
                <span class="card-emoji">📁</span>
                <h3 class="card-title">Load File</h3>
            </div>
        </div>
    </div>
    
    <script>
        function executeAction(action) {
            console.log('RFID action:', action);
            
            const card = event.currentTarget;
            card.style.transform = 'scale(0.95)';
            setTimeout(() => {
                card.style.transform = '';
            }, 150);
            
            
        }

        document.addEventListener('DOMContentLoaded', function() {
            const cards = document.querySelectorAll('.rfid-card');
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
