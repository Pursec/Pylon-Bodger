params["_ctrl"];
ctClear _ctrl;
ctAddHeader _ctrl params ["_index", "_header"];
_header params ["_headerBackground", "_column1", "_column2"];
_headerBackground ctrlSetBackgroundColor [0.102,0.302,0.102,1];
_column1 ctrlSetText "Pylon Slot";
_column2 ctrlSetText "Priority";

_pylonsInfo = getAllPylonsInfo editingVehicle;
_index = 0;
if (prioritiesArray isEqualTo [])then{
	{
		private _pylonName = _x#1;
		private _prio = [(configFile >> "CfgVehicles" >> typeOf editingVehicle >> "Components" >> "TransportPylonsComponent" >> "Pylons" >> _pylonName), "priority",1] call BIS_fnc_returnConfigEntry;
		prioritiesArray set [(_x#0)-1, _prio]
	}forEach _pylonsInfo;
};
{
	_pylonIndex = _x#0;
	_pylonName = _x#1;
	_turret = _x#2;
	_pylonCurrentMagazine = [(configFile >> "CfgMagazines" >> (_x#3)), "displayName", _x#3] call BIS_fnc_returnConfigEntry;
	
	ctAddRow _ctrl params["_index", "_row"];
	_row params["_background", "_pylonSlotText", "_subTractButton", "_priorityNumber", "_addButton"];
	
	_background ctrlSetBackgroundColor[0.6,0.6,0.6,0.8];

	_pylonSlotText ctrlSetText format["(%1) %2 : %3", _pylonIndex, _pylonName, if(_pylonCurrentMagazine isEqualTo "")then{"<Empty>"}else{_pylonCurrentMagazine}];
	_pylonSlotText ctrlSetTextColor[0.2,0.302,0.702,1];
	_priorityNumber ctrlSetShadow 2;

	_prio = prioritiesArray select _index;
	
	_priorityNumber ctrlSetText str(_prio);
	_priorityNumber ctrlSetShadow 2;

	_ctrl ctSetValue [_index, _prio];

	_subTractButton ctrlSetText "-";
	_subTractButton ctrlAddEventHandler["ButtonClick", format["_numChange = if(uiNameSpace getVariable 'shiftHeld')then{5}else{1};_num = ((displayCtrl %2) ctValue %3); ctrlSetText [%1,str((_num-_numChange) max 0)]; displayCtrl %2 ctSetValue[%3,(_num-_numChange) max 0]", ctrlIdc _priorityNumber, ctrlIdc _ctrl,_index]];
	_subTractButton ctrlSetBackgroundColor[0.7869,0.3612,0.3612,1];
	// Highest priority num you can set to
	_highestNum = 99;
	_addButton ctrlSetText "+";
	_addButton ctrlAddEventHandler["ButtonClick", format["_numChange = if(uiNameSpace getVariable 'shiftHeld')then{5}else{1};_num = ((displayCtrl %2) ctValue %3); ctrlSetText [%1,str((_num+_numChange) min %4)]; displayCtrl %2 ctSetValue[%3,(_num+_numChange) min %4]", ctrlIdc _priorityNumber, ctrlIdc _ctrl,_index, _highestNum]];
	_addButton ctrlSetBackgroundColor[0.4,0.6,0.4,1];
	_index = _index + 1;
}forEach _pylonsInfo;

