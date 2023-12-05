//Sistema de Misiones Dinámicas:

myEnvironment.insertSymbol("current_mission", "Elimina al jefe final");
// ... En el juego ...
if (playerDefeatedBoss) {
// Completa la misión actual y activa la siguiente.
completeCurrentMission();
activateNextMission();
}
