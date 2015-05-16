# Enigma
Enigma Machine Emulator C++

This project will emulate the World War 2 Enigma machine using authentic rotor and reflector configurations. 

The plugboard configuration, number; types, and order of rotors; type of reflector, and initialization vector for rotor starting potisions will be configurable from command-line arguments, or .ini cofiguration file.

The intended mode of operation is to read a text stream from stdin and write out the oposite encoding to stdout.

According to https://en.wikipedia.org/wiki/Enigma_machine#Details, the initialization settings which need to be considered are:

- Wheel order (Walzenlage) – the choice of rotors and the order in which they are fitted.
- Initial position of the rotors – chosen by the operator, different for each message.
- Ring settings (Ringstellung) – the position of the alphabet ring relative to the rotor wiring.
- Plug connections (Steckerverbindungen) – the connections of the plugs in the plugboard.
- In very late versions, the wiring of the reconfigurable reflector.
