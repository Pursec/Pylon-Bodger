params["_loadOutName"];
if (isNil {profileNameSpace getVariable "savedBodgedLoadOuts"})exitWith{};

_savedLoadOuts = profileNameSpace getVariable "savedBodgedLoadOuts";

_savedLoadOuts deleteAt _loadOutName;

profileNamespace setVariable ["savedBodgedLoadOuts", _savedLoadOuts];


