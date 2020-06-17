// REALIZADO CON API. Estructura de API, modificaciones y adaptaciones por Esteban Morales.
// Contenedor de extension. 

//Declaracion de constantes necesarias
const vscode = require('vscode');
const { title } = require('process');
const { Script } = require('vm');

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

	// Mensaje en pantalla.
		vscode.window.showInformationMessage('La extension esta activada correctamente');		

			const htmlContent = `<!DOCTYPE html>
			<html lang = "en">
			<head>
				<meta charset="UTF-8" />
				<meta name="viewpport" content="width=device-width, initial-scale=1.0" />
				<meta http-equiv="X-UA-Compatible" content="ie=edge" />
				<title>Document</title>
				<link rel="stylesheet" href="app.css" />
			</head>
			<body>
				<script src="app.js"></script>
			</body>
			</html>`;
	});

	context.subscriptions.push(disposable);
}

exports.activate = activate;

// this method is called when your extension is deactivated
function deactivate() {}

module.exports = {
	activate,
	deactivate
}