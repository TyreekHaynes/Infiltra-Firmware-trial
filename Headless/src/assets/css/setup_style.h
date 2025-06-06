#ifndef ASSETS_CSS_SETUP_STYLE_H
#define ASSETS_CSS_SETUP_STYLE_H

#include <Arduino.h>

const char SETUP_STYLE_CSS[] PROGMEM = R"rawliteral(
.setup-container {
    max-width: 600px;
    margin: 0 auto;
    background-color: rgba(10, 17, 40, 0.8);
    border: 1px solid rgba(56, 182, 255, 0.3);
    border-radius: 12px;
    padding: 2.5rem;
    backdrop-filter: blur(10px);
    box-shadow: 0 10px 30px rgba(0, 0, 0, 0.3);
}

.setup-title {
    font-family: 'Orbitron', sans-serif;
    font-size: 2rem;
    margin-bottom: 2rem;
    text-align: center;
    color: var(--neon-blue);
    text-shadow: 0 0 10px rgba(56, 182, 255, 0.3);
}

.form-group {
    margin-bottom: 1.5rem;
}

.form-label {
    display: block;
    margin-bottom: 0.5rem;
    font-size: 0.9rem;
    color: var(--text-white);
}

.form-input {
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

.form-input:focus {
    outline: none;
    border-color: var(--neon-blue);
    box-shadow: 0 0 0 2px rgba(56, 182, 255, 0.2);
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

.form-select {
    width: 100%;
    padding: 1rem;
    background-color: rgba(3, 11, 33, 0.8);
    border: 1px solid rgba(56, 182, 255, 0.3);
    border-radius: 6px;
    color: var(--text-white);
    font-family: 'Space Mono', monospace;
    box-shadow: inset 0 1px 3px rgba(0, 0, 0, 0.2);
}

.form-select option {
    background-color: var(--dark-blue);
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

.setup-footer {
    text-align: center;
    margin-top: 2rem;
    font-size: 0.8rem;
    color: rgba(255, 255, 255, 0.5);
}

.setup-logo {
    text-align: center;
    margin-bottom: 2rem;
}

.setup-logo i {
    font-size: 3rem;
    background: linear-gradient(45deg, var(--neon-blue), var(--neon-green));
    -webkit-background-clip: text;
    background-clip: text;
    color: transparent;
}

.setup-section {
    border-bottom: 1px solid rgba(56, 182, 255, 0.1);
    padding-bottom: 1.5rem;
    margin-bottom: 1.5rem;
}

.setup-section:last-child {
    border-bottom: none;
    padding-bottom: 0;
    margin-bottom: 0;
}

.setup-section-title {
    font-family: 'Orbitron', sans-serif;
    font-size: 1.3rem;
    margin-bottom: 1.5rem;
    color: var(--neon-green);
    position: relative;
    padding-left: 1rem;
}

.setup-section-title::before {
    content: '';
    position: absolute;
    left: 0;
    top: 0;
    bottom: 0;
    width: 3px;
    background: linear-gradient(to bottom, var(--neon-green), transparent);
    border-radius: 3px;
}

.password-toggle {
    position: relative;
}

.password-toggle i {
    position: absolute;
    right: 10px;
    top: 50%;
    transform: translateY(-50%);
    cursor: pointer;
    color: rgba(255, 255, 255, 0.5);
}

.password-toggle i:hover {
    color: var(--neon-blue);
}

.password-strength {
    height: 5px;
    background-color: rgba(255, 255, 255, 0.1);
    margin-top: 0.5rem;
    border-radius: 3px;
    overflow: hidden;
}

.password-strength-bar {
    height: 100%;
    width: 0%;
    transition: width 0.3s ease, background-color 0.3s ease;
}

.strength-weak { background-color: var(--neon-red); width: 33%; }
.strength-medium { background-color: #FFC107; width: 66%; }
.strength-strong { background-color: var(--neon-green); width: 100%; }
)rawliteral";

#endif