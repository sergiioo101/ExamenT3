//Personalización de Habilidades del Jugador:

myEnvironment.insertSymbol("player_skills", std::vector<std::string>{"Salto doble", "Ataque potenciado"});
// ... En el juego ...
std::vector<std::string> playerSkills = myEnvironment.lookup("player_skills").value<std::vector<std::string>>();
// Usa playerSkills para determinar las habilidades del jugador durante el juego.

