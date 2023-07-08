params["_selectedPylons", "_magazine", "_vehicle", ["_turret", []]];

_currentPylonsInfo = getAllPylonsInfo _vehicle;
_allTurrets = [[-1]] + allTurrets _vehicle;
_originalPylonsInfo = + _currentPylonsInfo;

{
	_pylonSlot = _currentPylonsInfo select _x;
	// setPylonLoadout requires [] for the driver turret rather than [-1] like EVERYTHING ELSE FSMR. This is to make it work.
	if(_turret isEqualTo [-1])then
	{
		_pylonSlot set [2, []];
	}
	else
	{
		_pylonSlot set [2, _turret];
	};
	if !(_magazine isEqualTo "")then{_pylonSlot set [3, _magazine];};
	_currentPylonsInfo set [_x, _pylonSlot];
}foreach _selectedPylons;


{
	_index = _forEachIndex;
	{
		if((_originalPylonsInfo select _index) select 3 isEqualTo "")then{
			continue;
		};
		_vehicle removeWeaponTurret [[configFile >> "CfgMagazines" >> (_originalPylonsInfo select _index) select 3, "pylonWeapon"] call BIS_fnc_returnConfigEntry, _x];
	}foreach _allTurrets;
	_vehicle setPylonLoadout[_forEachIndex + 1, _x select 3, true, _x select 2];
}forEach _currentPylonsInfo;




