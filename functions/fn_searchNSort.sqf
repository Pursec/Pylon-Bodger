// This should all be called in uiNamespace
// Display variables assigned onLoad in GESPylonUI.hpp
params ["_control", "_newText"];

[_control, _newText] spawn{
	params ["_control", "_newText"];
	lastTextInput = _newText;
	if (count _newText == 0) exitWith {[pylonsList] call GES_fnc_updatePylonMagazineList};
	_itemCount = count pylonsList;
	_Index = 0;
	_searchedArray = [] + pylonsList;
	while {_itemCount > 0}do{
		private _currentItemDisplayName =  _searchedArray select _Index select 0;
		if ((_currentItemDisplayName isEqualTo "") || {((([toUpper _currentItemDisplayName] call BIS_fnc_filterString) find ([toUpper _newText] call BIS_fnc_filterString)) == -1)}) then {
			_searchedArray deleteAt _Index;
		} else {
			_Index = _Index + 1;
		};
		_itemCount = _itemCount - 1;
	};
	[_searchedArray] call GES_fnc_updatePylonMagazineList;
}