params ["_logic"];

private _unit = attachedTo _logic;
if (isNull _unit)exitWith{hint "Place on a Vehicle"};
uiNameSpace setVariable ["editingVehicle",  _unit];
createDialog "RscGESPylonUI";
deleteVehicle _logic;

