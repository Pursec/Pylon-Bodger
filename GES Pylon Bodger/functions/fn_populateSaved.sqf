params["_pylonCount"];
lbClear SAVEDLOADOUTSLIST;
_hasLoadOuts = !isNil {
	profileNamespace getVariable "savedBodgedLoadOuts";
};

if (!_hasLoadOuts) exitWith {};
_savedLoadOuts = profileNamespace getVariable "savedBodgedLoadOuts";
_index = 0;
{
	private _name = _x;
	private _numPylons = _y get "numPylons";
	private _loadOut = _y get "loadOutData";
	private _originalVehicle = _y get "originalVehicle";
	SAVEDLOADOUTSLIST lbAdd _name;
	SAVEDLOADOUTSLIST lbSetData [_index, _loadOut];
	SAVEDLOADOUTSLIST lbSetTooltip[_index, format["(%2 Pylons)Loadout saved for: %1",_originalVehicle, _numPylons]];
	if(_pylonCount == _numPylons)then{
		SAVEDLOADOUTSLIST lbSetColor [_index, [1,1,1,1]];
	}else{
		SAVEDLOADOUTSLIST lbSetColor [_index, [.5,.5,.5,1]];
	};
	_index = _index + 1;	
}forEach _savedLoadOuts;
