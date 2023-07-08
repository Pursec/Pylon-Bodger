params["_name", "_numPylons", "_priorities"];
_savedLoadOuts = createHashMap;
if (!isNil {profileNameSpace getVariable "savedBodgedLoadOuts"})then{
	_savedLoadOuts = profileNameSpace getVariable "savedBodgedLoadOuts";
};


_exit = false;
if(_name in _savedLoadOuts)then{
		_diag = createDialog ["GESOverwriteConfirm", true];
		waitUntil{isNull _diag};
		if(OVERWRITE)exitWith{[_name] call GES_fnc_deleteLoadOut;};
		_exit = true;
};
if(_exit)exitWith{};

_newLoadOut = createHashMap;
_newLoadOut set ["numPylons", _numPylons];

_loadOutFunc = [editingVehicle, true, true] call GES_fnc_exportLoadOut;

_newLoadOut set ["loadOutData", _loadOutFunc];
_newLoadOut set ["originalVehicle", [configFile >> "cfgVehicles">> typeOf editingVehicle] call BIS_fnc_displayName];
_savedLoadOuts set [_name, _newLoadOut];

profileNamespace setVariable ["savedBodgedLoadOuts", _savedLoadOuts];
[count getAllPylonsInfo editingVehicle] call GES_fnc_populateSaved;