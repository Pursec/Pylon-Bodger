// This should all be called in uiNamespace
// Display variables assigned onLoad in GESPylonUI.hpp
// editingVehicle is assigned on module placement, tldr its the unit the module is attachedTo/placed on, held in uiNamespace. For more see: fn_moduleEditPylons.sqf
_pylonsInfo = getAllPylonsInfo editingVehicle;
lbClear VEHICLEPYLONS;

_index = 0;
{
	_pylonIndex = _x#0;
	_pylonName = _x#1;
	_turret = _x#2;
	_pylonCurrentMagazine = [(configFile >> "CfgMagazines" >> (_x#3)), "displayName", _x#3] call BIS_fnc_returnConfigEntry;
	VEHICLEPYLONS lbAdd format["(%1) %2 : %3", _pylonIndex, _pylonName, if(_pylonCurrentMagazine isEqualTo "")then{"<Empty>"}else{_pylonCurrentMagazine}];
	VEHICLEPYLONS lbSetData[_index, _pylonName];
	VEHICLEPYLONS lbSetTooltip[_index, format["(%1) %2 : %3", _pylonIndex, _pylonName, if(_pylonCurrentMagazine isEqualTo "")then{"<Empty>"}else{_pylonCurrentMagazine}]];
	if(_turret isEqualTo [-1])then
		{VEHICLEPYLONS lbSetPictureRight [_index, "a3\ui_f\data\IGUI\RscIngameUI\RscUnitInfo\role_driver_ca.paa"]}
	else
		{VEHICLEPYLONS lbSetPictureRight [_index, "a3\ui_f\data\IGUI\RscIngameUI\RscUnitInfo\role_gunner_ca.paa"]};
	_index = _index + 1;
} forEach _pylonsInfo;
