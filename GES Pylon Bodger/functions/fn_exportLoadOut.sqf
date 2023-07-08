params["_vehicle", "_exportSQF", "_exportForSaving"];


_exportString = "";

_loadout = getAllPylonsInfo _vehicle;
if(prioritiesArray isEqualTo [])then{
	{
		_pylonName = _x#1;
		_prio = [(configFile >> "CfgVehicles" >> typeOf editingVehicle >> "Components" >> "TransportPylonsComponent" >> "Pylons" >> _pylonName), "priority",1] call BIS_fnc_returnConfigEntry;
		prioritiesArray append [_prio];
	}forEach _loadout;
};
_allTurrets = [[-1]] + allTurrets _vehicle;
_vehicleType = [configFile >> "cfgVehicles">> typeOf _vehicle] call BIS_fnc_displayName;
_object = "this";
if (_exportSQF) then
{
	if(!_exportForSaving) then{_exportString = _exportString + format["//Custom Loadout for: %1", _vehicleType] + endl;};
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
		if((_originalLoadOut select _index) select 3 isEqualTo """")then{
			continue;
		};
		%1 removeWeaponTurret [[configFile >> ""CfgMagazines"" >> (_originalLoadout select _index) select 3, ""pylonWeapon""] call BIS_fnc_returnConfigEntry, _x];
	}foreach _allTurrets;
	%1 setPylonLoadout[_forEachIndex + 1, _x select 3, true, _x select 2];
}forEach _loadout;
%1 setVariable [""pylonPriority"", %2];
%1 setPylonsPriority %2;
	"
	,_object, prioritiesArray];
if (!_exportForSaving) then{
	if (_exportSQF)then{[]spawn{hint "Format: SQF\n Copied loadout to clipboard!";sleep 15; hintSilent "";}}else{[]spawn{hint "Format: INIT\n Copied loadout to clipboard!";sleep 15;hintSilent"";}};
};
_exportString;
