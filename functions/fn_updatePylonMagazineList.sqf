// This should all be called in uiNamespace
// Display variables assigned onLoad in GESPylonUI.hpp

params [["_list", pylonsList]];

lbClear MAGAZINELIST;
_index = 0;
{
	_magazineName = _x select 0;
	_magazineShortDescription = _x select 1;
	_configName = _x select 2;
	MAGAZINELIST lbAdd _magazineName;
	MAGAZINELIST lbSetData[_index, _configName];
	MAGAZINELIST lbData _index;
	MAGAZINELIST lbSetTooltip[_index, _magazineShortDescription];
	_index = _index + 1;
}forEach _list;
