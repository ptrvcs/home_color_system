# Home Color System

## The Core Idea

A modular lighting control application built with **C++**, **Qt**, and **Bazel**.  
The system allows color control of DMX lamps via a modern GUI interface and integrates with MIDI input devices for real-time adjustments.

---

## How to run
- Open in devcontainer in vscode
- bazel run //:dmx_gui

## Visualization

Qt uses a publish–subscribe or observer pattern to let objects communicate without tight coupling.

A signal is emitted by an object when something happens (like “value changed”).

A slot is a function that reacts to that signal.

You connect signals to slots → when the signal fires, the slot runs automatically.

- Signal = event publisher
- Slot = event listener
- emit = trigger the signal