// This should all be called in uiNamespace
// Display variables assigned onLoad in GESPylonUI.hpp

_pylonWeaponsMagazines = configProperties [configFile >> "CfgMagazines", ' _isPylonWeapon = ([_x, "pylonWeapon", nil] call BIS_fnc_returnConfigEntry); (typeName _isPylonWeapon) == "STRING"', true];
pylonsList = [];
_index = 0;
{
	_magazineName = ([_x, "displayName", configName _x] call BIS_fnc_returnConfigEntry);
	_magazineShortDescription = ([_x, "descriptionShort", configName _x] call BIS_fnc_returnConfigEntry);
	pylonsList pushBack [_magazineName, _magazineShortDescription, configName _x];
	_index = _index + 1;
}forEach _pylonWeaponsMagazines;

 