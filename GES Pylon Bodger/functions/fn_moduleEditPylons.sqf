params ["_logic"];

private _unit = attachedTo _logic;
if (isNull _unit)exitWith{hint "Place on a Vehicle"; deleteVehicle _logic;};
if !([configFile >> "CfgVehicles" >> typeOf _unit >> "Components" >> "TransportPylonsComponent"] call BIS_fnc_getCfgIsClass)exitWith{hint "Vehicle must have pylon slots"; deleteVehicle _logic;};
uiNameSpace setVariable ["editingVehicle",  _unit];
createDialog "RscGESPylonUI";
deleteVehicle _logic;

