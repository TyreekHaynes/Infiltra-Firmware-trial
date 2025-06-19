#ifndef ASSETS_CSS_STYLE_H
#define ASSETS_CSS_STYLE_H

const char STYLE_CSS[] PROGMEM = R"rawliteral(@import url('https://fonts.googleapis.com/css2?family=Syncopate:wght@400;700&family=Space+Mono:wght@400;700&family=Orbitron:wght@400;500;700&display=swap');

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

::-webkit-scrollbar { width: 8px; }
::-webkit-scrollbar-track { background: var(--darker-blue); }
::-webkit-scrollbar-thumb { 
    background: var(--accent-blue); 
    border-radius: 4px;
}
::-webkit-scrollbar-thumb:hover { background: var(--neon-blue); }

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

.header {
    margin-bottom: 4rem;
    text-align: center;
    position: relative;
}

.glitch-container {
    position: relative;
    display: inline-block;
    margin-bottom: 1rem;
}

.title {
    font-family: 'Syncopate', sans-serif;
    font-size: 3.5rem;
    font-weight: 700;
    text-transform: uppercase;
    letter-spacing: 0.2em;
    position: relative;
    padding: 0.5rem 0;
    text-shadow: 0 0 10px rgba(56, 182, 255, 0.3);
    background: linear-gradient(to right, var(--text-white), var(--neon-blue), var(--text-white));
    -webkit-background-clip: text;
    background-clip: text;
    color: transparent;
}

.tagline {
    font-size: 1.2rem;
    color: rgba(255, 255, 255, 0.7);
    letter-spacing: 0.1em;
    margin-top: 1rem;
    font-family: 'Orbitron', sans-serif;
    display: inline-block;
    background: linear-gradient(to right, var(--neon-blue), var(--neon-green));
    -webkit-background-clip: text;
    background-clip: text;
    color: transparent;
}

.subtitle {
    max-width: 700px;
    margin: 2rem auto 0;
    color: rgba(255, 255, 255, 0.6);
    font-size: 1rem;
    line-height: 1.6;
    position: relative;
    padding-bottom: 2rem;
}

.subtitle::after {
    content: '';
    position: absolute;
    bottom: 0;
    left: 50%;
    transform: translateX(-50%);
    width: 50px;
    height: 1px;
    background: linear-gradient(to right, transparent, var(--neon-blue), transparent);
}

.modules-container {
    perspective: 1000px;
    transform-style: preserve-3d;
    margin-bottom: 3rem;
}

.modules-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
    gap: 1.8rem;
    transform-style: preserve-3d;
}

.module {
    background-color: rgba(10, 17, 40, 0.7);
    border: 1px solid rgba(56, 182, 255, 0.1);
    backdrop-filter: blur(5px);
    overflow: hidden;
    position: relative;
    transition: all 0.3s cubic-bezier(0.16, 1, 0.3, 1);
    cursor: pointer;
    padding: 0;
    border-radius: 8px;
    transform-style: preserve-3d;
    transform: translateZ(0);
    box-shadow: 0 4px 20px rgba(0, 0, 0, 0.2);
    min-height: 200px;
}

.module::before {
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

.module:hover::before { transform: scaleX(1); }

.module-inner {
    padding: 2rem;
    position: relative;
    z-index: 1;
    display: flex;
    flex-direction: column;
    align-items: center;
    text-align: center;
    height: 100%;
}

.module::after {
    content: '';
    position: absolute;
    width: 200%;
    height: 200%;
    top: -50%;
    left: -50%;
    background: radial-gradient(circle at center, transparent 30%, var(--midnight) 70%);
    opacity: 0;
    transition: opacity 0.3s ease;
    pointer-events: none;
}

.module:hover {
    transform: translateY(-10px) translateZ(20px);
    box-shadow: 0 15px 30px rgba(4, 102, 200, 0.2);
    border-color: rgba(56, 182, 255, 0.3);
}

.module:hover::after { opacity: 0.5; }

.module-icon {
    font-size: 3rem;
    margin-bottom: 1.5rem;
    transition: all 0.3s ease;
    display: inline-block;
    width: 80px;
    height: 80px;
    line-height: 80px;
    text-align: center;
    border-radius: 50%;
    background: rgba(4, 102, 200, 0.1);
    position: relative;
}

.module-icon i {
    background: linear-gradient(45deg, var(--neon-blue), var(--accent-blue));
    -webkit-background-clip: text;
    background-clip: text;
    color: transparent;
    filter: drop-shadow(0 0 5px rgba(56, 182, 255, 0));
    transition: filter 0.3s ease;
}

.module-icon::after {
    content: '';
    position: absolute;
    top: -5px;
    left: -5px;
    right: -5px;
    bottom: -5px;
    border-radius: 50%;
    border: 1px solid rgba(56, 182, 255, 0.2);
    animation: pulse-ring 2s infinite;
}

@keyframes pulse-ring {
    0% { transform: scale(0.8); opacity: 0.3; }
    50% { transform: scale(1); opacity: 0.1; }
    100% { transform: scale(0.8); opacity: 0.3; }
}

.module:hover .module-icon {
    transform: scale(1.1);
    background: rgba(4, 102, 200, 0.2);
}

.module:hover .module-icon i {
    filter: drop-shadow(0 0 8px rgba(56, 182, 255, 0.5));
}

.module-title {
    font-family: 'Orbitron', sans-serif;
    font-size: 1.5rem;
    color: white;
    margin-bottom: 1rem;
    text-transform: uppercase;
    letter-spacing: 0.05em;
    position: relative;
    padding-bottom: 1rem;
}

.module-title::after {
    content: '';
    position: absolute;
    bottom: 0;
    left: 50%;
    transform: translateX(-50%);
    width: 30px;
    height: 2px;
    background: linear-gradient(to right, var(--neon-blue), transparent);
    transition: width 0.3s ease;
}

.module:hover .module-title::after { width: 70px; }

.module-stats {
    display: flex;
    flex-wrap: wrap;
    gap: 1rem;
    justify-content: center;
    margin-top: auto;
    font-size: 0.75rem;
    color: rgba(255, 255, 255, 0.5);
}

.module-stat {
    display: flex;
    align-items: center;
    gap: 0.3rem;
}

.data-line {
    position: absolute;
    height: 1px;
    background-color: rgba(56, 182, 255, 0.2);
    width: 100px;
    bottom: 0;
    transform-origin: left;
    animation: dataMove 4s infinite linear;
    opacity: 0;
}

@keyframes dataMove {
    0% { transform: scaleX(0); opacity: 0.5; }
    50% { transform: scaleX(1); opacity: 0.2; }
    100% { transform: scaleX(0); opacity: 0; }
}

.footer {
    margin-top: auto;
    padding: 2rem;
    background-color: rgba(3, 11, 33, 0.5);
    border-top: 1px solid rgba(56, 182, 255, 0.1);
    display: flex;
    flex-direction: column;
    gap: 1.5rem;
}

.footer-top {
    display: flex;
    justify-content: space-between;
    align-items: center;
    flex-wrap: wrap;
    gap: 1rem;
}

.stats-container {
    display: flex;
    gap: 2rem;
    flex-wrap: wrap;
}

.stat-item {
    display: flex;
    flex-direction: column;
    gap: 0.3rem;
}

.stat-label {
    font-size: 0.75rem;
    color: rgba(255, 255, 255, 0.5);
    text-transform: uppercase;
}

.stat-value {
    font-family: 'Orbitron', sans-serif;
    font-size: 1rem;
    color: var(--neon-blue);
}

.footer-bottom {
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding-top: 1.5rem;
    border-top: 1px solid rgba(255, 255, 255, 0.05);
    color: rgba(255, 255, 255, 0.4);
    font-size: 0.8rem;
}

.footer-links {
    display: flex;
    gap: 1.5rem;
}

.footer-link {
    color: rgba(255, 255, 255, 0.5);
    text-decoration: none;
    transition: color 0.3s ease;
}

.footer-link:hover { color: var(--neon-blue); }

.typing::after {
    content: '|';
    animation: blink 1s infinite;
}

@keyframes blink {
    0%, 100% { opacity: 1; }
    50% { opacity: 0; }
}

.module {
    opacity: 0;
    animation: fadeInUp 0.6s forwards cubic-bezier(0.19, 1, 0.22, 1);
}

@keyframes fadeInUp {
    from {
        opacity: 0;
        transform: translateY(30px);
    }
    to {
        opacity: 1;
        transform: translateY(0);
    }
}

.module:nth-child(1) { animation-delay: 0.2s; }
.module:nth-child(2) { animation-delay: 0.3s; }
.module:nth-child(3) { animation-delay: 0.4s; }
.module:nth-child(4) { animation-delay: 0.5s; }
.module:nth-child(5) { animation-delay: 0.6s; }
.module:nth-child(6) { animation-delay: 0.7s; }
.module:nth-child(7) { animation-delay: 0.8s; }
.module:nth-child(8) { animation-delay: 0.9s; }

/* Form elements styling for setup page */
.form-input, .form-select {
    width: 100%;
    padding: 1rem;
    background-color: rgba(3, 11, 33, 0.8);
    border: 1px solid rgba(56, 182, 255, 0.3);
    border-radius: 6px;
    color: var(--text-white);
    font-family: 'Space Mono', monospace;
    transition: all 0.3s ease;
    box-shadow: inset 0 1px 3px rgba(0, 0, 0, 0.2);
}

.form-input:focus, .form-select:focus {
    outline: none;
    border-color: var(--neon-blue);
    box-shadow: 0 0 0 2px rgba(56, 182, 255, 0.2);
}

.form-label {
    display: block;
    margin-bottom: 0.5rem;
    font-size: 0.9rem;
    color: var(--text-white);
}

.form-check {
    display: flex;
    align-items: center;
    margin-bottom: 0.5rem;
}

.form-check-input {
    margin-right: 0.5rem;
    width: 16px;
    height: 16px;
    accent-color: var(--neon-blue);
}

.form-help {
    font-size: 0.8rem;
    color: rgba(255, 255, 255, 0.5);
    margin-top: 0.5rem;
}

.form-submit {
    display: block;
    width: 100%;
    padding: 1.2rem;
    background: linear-gradient(90deg, var(--accent-blue), var(--neon-blue));
    border: none;
    border-radius: 6px;
    color: white;
    font-family: 'Orbitron', sans-serif;
    font-size: 1.1rem;
    text-transform: uppercase;
    letter-spacing: 2px;
    cursor: pointer;
    transition: all 0.3s ease;
    margin-top: 2.5rem;
    box-shadow: 0 4px 15px rgba(56, 182, 255, 0.3);
}

.form-submit:hover {
    transform: translateY(-2px);
    box-shadow: 0 5px 15px rgba(56, 182, 255, 0.3);
}

@media (max-width: 768px) {
    .title { font-size: 2.5rem; }
    .nav { padding: 1rem; }
    .nav-status { display: none; }
    .modules-grid { grid-template-columns: 1fr; }
    
    .footer-top {
        flex-direction: column;
        align-items: flex-start;
    }
    
    .footer-bottom {
        flex-direction: column;
        gap: 1rem;
        align-items: flex-start;
    }
})rawliteral";

#endif
