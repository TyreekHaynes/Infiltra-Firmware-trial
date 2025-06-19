#ifndef ASSETS_CSS_RF_STYLE_H
#define ASSETS_CSS_RF_STYLE_H

const char RF_STYLE_CSS[] PROGMEM = R"rawliteral(
@import url('https://fonts.googleapis.com/css2?family=Syncopate:wght@400;700&family=Space+Mono:wght@400;700&family=Orbitron:wght@400;500;700&display=swap');

* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

:root {
    --dark-blue: #0a1128;
    --darker-blue: #030b21;
    --midnight: #05070f;
    --accent-blue: #0466c8;
    --neon-blue: #38b6ff;
    --neon-green: #00ff9d;
    --neon-red: #ff3864;
    --text-white: #e6e6e6;
}

body {
    font-family: 'Space Mono', monospace;
    background-color: var(--midnight);
    color: var(--text-white);
    min-height: 100vh;
    overflow-x: hidden;
}

.background {
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    z-index: -1;
    overflow: hidden;
}

.grid {
    position: absolute;
    width: 200%;
    height: 200%;
    top: -50%;
    left: -50%;
    background-image: 
        linear-gradient(rgba(56, 182, 255, 0.03) 1px, transparent 1px),
        linear-gradient(90deg, rgba(56, 182, 255, 0.03) 1px, transparent 1px);
    background-size: 25px 25px;
    transform: perspective(500px) rotateX(60deg);
    animation: gridMove 35s linear infinite;
}

@keyframes gridMove {
    0% { background-position: 0 0; }
    100% { background-position: 0 25px; }
}

.noise::before {
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    content: "";
    opacity: 0.05;
    z-index: -1;
    pointer-events: none;
    background-image: url("data:image/svg+xml,%3Csvg viewBox='0 0 200 200' xmlns='http://www.w3.org/2000/svg'%3E%3Cfilter id='noiseFilter'%3E%3CfeTurbulence type='fractalNoise' baseFrequency='0.65' numOctaves='3' stitchTiles='stitch'/%3E%3C/filter%3E%3Crect width='100%25' height='100%25' filter='url(%23noiseFilter)'/%3E%3C/svg%3E");
}

.nav {
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    padding: 1rem 2rem;
    display: flex;
    justify-content: space-between;
    align-items: center;
    z-index: 100;
    backdrop-filter: blur(5px);
    background-color: rgba(3, 11, 33, 0.6);
    border-bottom: 1px solid rgba(56, 182, 255, 0.1);
}

.nav-logo {
    font-family: 'Orbitron', sans-serif;
    font-weight: 700;
    font-size: 1.2rem;
    letter-spacing: 2px;
    color: var(--neon-blue);
    text-transform: uppercase;
}

.nav-status {
    display: flex;
    align-items: center;
    gap: 1.5rem;
    font-size: 0.75rem;
}

.status-item {
    display: flex;
    align-items: center;
    gap: 0.5rem;
}

.status-dot {
    width: 8px;
    height: 8px;
    border-radius: 50%;
    background-color: var(--neon-green);
    position: relative;
}

.status-dot::after {
    content: '';
    position: absolute;
    top: -2px;
    left: -2px;
    width: 12px;
    height: 12px;
    border-radius: 50%;
    background-color: transparent;
    border: 1px solid var(--neon-green);
    opacity: 0.5;
    animation: pulse 2s infinite;
}

@keyframes pulse {
    0% { transform: scale(1); opacity: 0.5; }
    50% { transform: scale(1.5); opacity: 0; }
    100% { transform: scale(1); opacity: 0; }
}

.main {
    width: 100%;
    max-width: 1400px;
    margin: 0 auto;
    padding: 6rem 2rem 2rem;
    display: flex;
    flex-direction: column;
    min-height: 100vh;
    justify-content: center;
}

.back-button {
    position: fixed;
    top: 80px;
    left: 2rem;
    z-index: 100;
    background: rgba(4, 102, 200, 0.1);
    border: 1px solid rgba(56, 182, 255, 0.3);
    color: var(--neon-blue);
    padding: 0.8rem 1.5rem;
    border-radius: 8px;
    text-decoration: none;
    font-family: 'Orbitron', sans-serif;
    font-size: 0.9rem;
    transition: all 0.3s ease;
    backdrop-filter: blur(5px);
}

.back-button:hover {
    background: rgba(4, 102, 200, 0.2);
    border-color: var(--neon-blue);
    transform: translateX(-5px);
}

.page-title {
    text-align: center;
    margin-bottom: 3rem;
    padding-top: 2rem;
}

.page-title h1 {
    font-family: 'Syncopate', sans-serif;
    font-size: 2.5rem;
    color: var(--neon-blue);
    text-transform: uppercase;
    letter-spacing: 0.2em;
    margin-bottom: 1rem;
}

.rf-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
    gap: 2rem;
    margin-bottom: 3rem;
}

.rf-card {
    background: rgba(10, 17, 40, 0.8);
    border: 1px solid rgba(56, 182, 255, 0.2);
    border-radius: 12px;
    padding: 2rem;
    position: relative;
    transition: all 0.3s ease;
    cursor: pointer;
    overflow: hidden;
    text-align: center;
    min-height: 180px;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
}

.rf-card::before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 4px;
    background: linear-gradient(90deg, var(--neon-blue), var(--neon-green));
    transform: scaleX(0);
    transform-origin: left;
    transition: transform 0.3s ease;
}

.rf-card:hover::before {
    transform: scaleX(1);
}

.rf-card:hover {
    transform: translateY(-8px);
    border-color: rgba(56, 182, 255, 0.4);
    box-shadow: 0 15px 30px rgba(4, 102, 200, 0.2);
}

.card-emoji {
    font-size: 3rem;
    margin-bottom: 1rem;
    display: block;
}

.card-title {
    font-family: 'Orbitron', sans-serif;
    font-size: 1.3rem;
    color: white;
    margin: 0;
    text-transform: uppercase;
    letter-spacing: 0.1em;
}

@media (max-width: 768px) {
    .rf-grid {
        grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
        gap: 1.5rem;
    }
    
    .page-title h1 {
        font-size: 2rem;
    }
    
    .back-button {
        left: 1rem;
        padding: 0.6rem 1rem;
        font-size: 0.8rem;
    }
}
)rawliteral";

#endif
