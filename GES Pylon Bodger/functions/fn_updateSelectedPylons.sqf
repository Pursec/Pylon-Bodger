params["_selectedPylons", "_magazine", "_vehicle", ["_turret", []]];

_currentPylonsInfo = getAllPylonsInfo _vehicle;
_allTurrets = [[-1]] + allTurrets _vehicle;
_originalPylonsInfo = + _currentPylonsInfo;

{
	_pylonSlot = _currentPylonsInfo select _x;
	// setPylonLoadout requires [] for the driver turret rather than [-1] like EVERYTHING ELSE FSMR. This is to make it work.
	// I have no clue when it was fixed, but testing shows it has been. Wiki needs a new comment adressing it.
	/*if(_turret isEqualTo [-1])then
	{
		_pylonSlot set[2, [-1]];
		//_pylonSlot set [2, []];
	}
	else
	{
		_pylonSlot set [2, _turret];
	};
	*/
	_pylonSlot set [2, _turret];
	if !(_magazine isEqualTo "")then{_pylonSlot set [3, _magazine];};
	_currentPylonsInfo set [_x, _pylonSlot];
}foreach _selectedPylons;

if(toUpper(getMissionConfigValue ["missionGroup", ""])  == "APEXFRAMEWORK")then{
	//Scuffed workaround because ApexFrameworks setPylonLoadOut remoteExec takes in an array for a preset rather than just the array of attachments - [_configName, _displayName, _loadoutData, {TRUE}, 0, 0 ,0]
	//The other elements past _loadOutData are used for things like laserDesignator turret removal and some stealth variable, but as far as I can tell they are by default when changing pylonLoadouts - such as their own hanger function
	//It just sets those to the values seen here
	//Within the function it grabs: _loadoutData # 2, its 3rd element or element at index: 2. Which is the array of pylonInfo in the format youd get from getAllPylonsInfo.
	diag_log("Attempting to set following loadout: %1");
	diag_log(_currentPylonsInfo);
	[105,_vehicle, ["bodgedLoadout", "customPylonsBodged",_currentPylonsInfo, {true}, 0, 0, 0]] remoteExec ['QS_fnc_remoteExec',0,FALSE];
}else{
	{
		_index = _forEachIndex;
		{
			if((_originalPylonsInfo select _index) select 3 isEqualTo "")then{
				continue;
			};
			//_vehicle removeWeaponTurret [[configFile >> "CfgMagazines" >> (_originalPylonsInfo select _index) select 3, "pylonWeapon"] call BIS_fnc_returnConfigEntry, _x];
			[_vehicle, [[configFile >> "CfgMagazines" >> (_originalPylonsInfo select _index) select 3, "pylonWeapon"] call BIS_fnc_returnConfigEntry, _x]] remoteExec ["removeWeaponTurret"];
		}foreach _allTurrets;
		//_vehicle setPylonLoadout[_forEachIndex + 1, _x select 3, true, _x select 2];
		[_vehicle, [_forEachIndex + 1, _x select 3, true, _x select 2]] remoteExec ["setPylonLoadout"];
	}forEach _currentPylonsInfo;
};





