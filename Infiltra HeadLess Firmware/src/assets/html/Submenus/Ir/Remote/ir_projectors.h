#ifndef ASSETS_HTML_IR_PROJECTORS_H
#define ASSETS_HTML_IR_PROJECTORS_H

const char IR_PROJECTORS_HTML[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IR Projectors | Infiltra Headless</title>
    <link rel="stylesheet" href="../ir_style.css">
</head>
<body>
    <div class="noise"></div>
    
    <nav class="nav">
        <div class="nav-logo">Infiltra</div>
        <div class="nav-status">
            <div class="status-item">
                <div class="status-dot"></div>
                <span>IR PROJECTORS</span>
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
            <h1>Projectors</h1>
        </div>
        
        <div class="ir-grid">
            <div class="ir-card" onclick="executeAction('epson-projector')">
                <span class="card-emoji">📽️</span>
                <h3 class="card-title">Epson Projector</h3>
            </div>

            <div class="ir-card" onclick="executeAction('benq-projector')">
                <span class="card-emoji">📽️</span>
                <h3 class="card-title">BenQ Projector</h3>
            </div>

            <div class="ir-card" onclick="executeAction('viewsonic-projector')">
                <span class="card-emoji">📽️</span>
                <h3 class="card-title">ViewSonic Projector</h3>
            </div>

            <div class="ir-card" onclick="executeAction('optoma-projector')">
                <span class="card-emoji">📽️</span>
                <h3 class="card-title">Optoma Projector</h3>
            </div>

            <div class="ir-card" onclick="executeAction('christie-projector')">
                <span class="card-emoji">📽️</span>
                <h3 class="card-title">Christie Projector</h3>
            </div>
        </div>
    </div>
    
    <script>
        function executeAction(action) {
            console.log('Projector action:', action);
            
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
