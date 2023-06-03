params["_vehicle", "_exportSQF"];

_exportString = "";

_loadout = getAllPylonsInfo _vehicle;
_allTurrets = [[-1]] + allTurrets _vehicle;
_vehicleType = [configFile >> "cfgVehicles">> typeOf _vehicle] call BIS_fnc_displayName;
_object = "this";
if (_exportSQF) then
{
	_exportString = _exportString + format["//Custom Loadout for: %1", _vehicleType] + endl;
	_exportString = _exportString + "params[""_vehicle""];" + endl;
	_object = "_vehicle";
};
_exportString = _exportString + format["_allTurrets = %1;", _allTurrets] + endl;
_exportString = _exportString + format["_loadout = %1;", _loadout] + endl;
_exportString = _exportString + format["_originalLoadOut = getAllPylonsInfo %1;", _object] + endl;
_exportString = _exportString + format
	[
	"
{
	_index = _forEachIndex;
	{
		%1 removeWeaponTurret [[configFile >> ""CfgMagazines"" >> (_originalLoadout select _index) select 3, ""pylonWeapon""] call BIS_fnc_returnConfigEntry, _x];
	}foreach _allTurrets;
	%1 setPylonLoadout[_forEachIndex + 1, _x select 3, true, _x select 2];
}forEach _loadout;
	"
	,_object];
copyToClipboard _exportString;
if (_exportSQF)then{hint "Format: SQF\n Copied loadout to clipboard!";}else{hint "Format: INIT\n Copied loadout to clipboard!";}

