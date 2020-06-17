// REALIZADO CON API. Estructura de API, modificaciones y adaptaciones por Esteban Morales.
// Contenedor de extension. 

//Declaracion de constantes necesarias
const vscode = require('vscode');

// Metodo llamado una vez activa la extension.

/**
 * @param {vscode.ExtensionContext} context
 */
function activate(context) {

	// Realice diagnostico con "console.log" y errores con "console.error", con la extension ACTIVA!
	console.log('Congratulations, your extension "memory-manager" is now active!');

	// Comando defino en package.json.
	// Implementacion de comando para mostar mensaje de activacion.
	let disposable = vscode.commands.registerCommand(
		'memory-manager.garbagecollector',
		 function () {
		//Mensaje en pantalla:
		vscode.window.showInformationMessage('Interfaz visual from memory-manager!');
	
	}
	);

	//Variable de alamacen de comando y fucion de inicio
	let init = vscode.commands.registerCommand('memory-manager.start',
	function(){

		// Mensaje en pantalla.
		vscode.window.showInformationMessage('La extension esta activada correctamente');

		

		// Creacion del HTML necesaio para el  webView
		

		
	

	context.subscriptions.push(disposable);

}

exports.activate = activate;

// this method is called when your extension is deactivated
function deactivate() {}

module.exports = {
	activate,
	deactivate
}