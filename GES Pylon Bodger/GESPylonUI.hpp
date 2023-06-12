#define PYLONUI 5567
#define MAGAZINELIST 5566
#define SEARCH 5555
#define VEHICLEPYLONS 5554
#define TURRETBUTTON 5553
#define LOADOUTMENUGROUP 5552
class ctrlButtonPictureKeepAspect;
class RscGESPylonUI
{
	idd = PYLONUI;
	movingEnable = true;
	onLoad = "uiNamespace setVariable ['PYLONUI', (_this select 0)];[]spawn{waitUntil {!isNil {uiNamespace getVariable 'PYLONUI'}}}";
	class ControlsBackground
	{
		class background
		{
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26875;
			y = safeZoneY + safeZoneH * 0.125;
			w = safeZoneW * 0.4625;
			h = safeZoneH * 0.7;
			style = 0;
			text = "";
			colorBackground[] = {0.302,0.302,0.302,0.85};
			colorText[] = {0.1137,0.4863,0.9333,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW/safezoneH)min 1.2)/1.2)/25)*1);
			shadow = 0;
			
		};
		class backgroundFrame
		{
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26775;
			y = safeZoneY + safeZoneH * 0.115;
			w = safeZoneW * 0.4635;
			h = safeZoneH * 0.711;
			style = 64+0;
			moving = true;
			text = "Vehicle Name";
			onLoad = "with uiNamespace do{_display = param[0]; _display ctrlSetText ([configFile >> ""cfgVehicles"">> typeOf editingVehicle] call BIS_fnc_displayName)}";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW/safezoneH)min 1.2)/1.2)/25)*1);
			shadow = 0;
			
		};
		class VehiclePylonsListBackground
		{
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.29375;
			y = safeZoneY + safeZoneH * 0.53981482;
			w = safeZoneW * 0.175;
			h = safeZoneH * 0.24907408;
			style = 0;
			text = "";
			colorBackground[] = {0.9098,0.7619,0.4997,0.8};
			colorText[] = {0.2,0.4,0.4,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW/safezoneH)min 1.2)/1.2)/25)*1);
			shadow = 0;
		};
		
	};
	class Controls
	{
		class fixListButtons : ctrlButtonPictureKeepAspect
		{
			type = 0;
			idc = -1;
			style = 0;
			x = -1;
			y = -1;
			w = -1;
			h = -1;
		};
		class MagazineListFrame
		{
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.29114584;
			y = safeZoneY + safeZoneH * 0.14092593;
			w = safeZoneW * 0.41770834;
			h = safeZoneH * 0.3655556;
			style = 0+64;
			text = "All Pylon Weapons";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class MagazinePylonList
		{
			type = 5;
			idc = MAGAZINELIST;
			x = safeZoneX + safeZoneW * 0.29375;
			y = safeZoneY + safeZoneH * 0.16388889;
			w = safeZoneW * 0.41197917;
			h = safeZoneH * 0.33611112;
			style = 16;
			colorBackground[] = {0.6,0.6,0.6,0.8};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelect[] = {1,0,0,1};
			colorText[] = {0.2,0.302,0.702,1};
			font = "PuristaBold";
			maxHistoryDelay = 0;
			rowHeight = 0;
			sizeEx = (((((safezoneW/safezoneH)min 1.2)/1.2)/25)*1);
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
			onLBSelChanged = "params['_control', '_lbCurSel', '_lbSelection'];with uiNamespace do{SEARCH ctrlSetText (MAGAZINELIST lbText _lbCurSel)}";
			onLoad = "uiNameSpace setVariable ['MAGAZINELIST', _this select 0]; with uiNamespace do {[]call GES_fnc_generatePylonMagazinesArray;[pylonsList] call GES_fnc_updatePylonMagazineList}";
			tooltipColorBox[] = {0,0,0,0};
			tooltipColorShade[] = {0.102,0.102,0.102,0.9};
			tooltipColorText[] = {1,1,1,1};
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class SearchBarFrame
		{
			type = 0;
			idc = 0;
			x = safeZoneX + safeZoneW * 0.48177084;
			y = safeZoneY + safeZoneH * 0.5112963;
			w = safeZoneW * 0.21858334;
			h = safeZoneH * 0.07851852;
			style = 0+64;
			text = "Search";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class Search
		{
			type = 2;
			idc = SEARCH;
			x = safeZoneX + safeZoneW * 0.48385417;
			y = safeZoneY + safeZoneH * 0.53333334;
			w = safeZoneW * 0.21197917;
			h = safeZoneH * 0.05092593;
			style = 0;
			maxChars = 18;
			text = "Pylon Name";
			autocomplete = "";
			colorBackground[] = {0.2,0.2,0.2,0.8};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelection[] = {1,0,0,1};
			colorText[] = {0.4,0.6,0.4,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW/safezoneH)min 1.2)/1.2)/25)*2);
			onKeyUp = "with uiNamespace do{[MAGAZINELIST, ctrlText SEARCH] call GES_fnc_searchNSort}";
			onLoad = "uiNameSpace setVariable ['SEARCH', _this select 0]; with uiNamespace do{lastTextInput = ''}";
			onSetFocus = "with uiNamespace do{if(ctrlText SEARCH isEqualTo 'Pylon Name')then{SEARCH ctrlSetText ''}}";
			
		};
		class CloseOk
		{
			type = 1;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.5140625;
			y = safeZoneY + safeZoneH * 0.62870371;
			w = safeZoneW * 0.14010417;
			h = safeZoneH * 0.07592593;
			style = 2;
			text = "OK";
			borderSize = 0;
			colorBackground[] = {0.102,0,0.4078,1};
			colorBackgroundActive[] = {1,0,0,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,1};
			colorText[] = {0.9412,0.8314,0.4275,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW/safezoneH)min 1.2)/1.2)/25)*1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			action = "with uiNamespace do{[lbSelection VEHICLEPYLONS, MAGAZINELIST lbData lbCurSel(MAGAZINELIST), editingVehicle, TURRET] call GES_fnc_updateSelectedPylons; [] call GES_fnc_loadVehiclePylons}";
			
		};
		class exitButton
		{
			type = 16;
			idc = 2;
			x = safeZoneX + safeZoneW * 0.71354167;
			y = safeZoneY + safeZoneH * 0.13148149;
			w = safeZoneW * 0.0125;
			h = safeZoneH * 0.025;
			style = 0;
			text = "X";
			animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureDisabled = "#(argb,8,8,3)color(0.2,0.2,0.2,1)";
			animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
			animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
			color[] = {1,1,1,1};
			color2[] = {0.6,0,0,1};
			colorBackground[] = {0.6,0,0,1};
			colorBackground2[] = {0.102,0.102,0.102,1};
			colorBackgroundFocused[] = {0,0,0,1};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {1,0.7131,0,1};
			font = "PuristaBold";
			size = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush",0.09,1.0};
			textureNoShortcut = "";
			class HitZone
			{
				top = 0;
				right = 0;
				bottom = 0;
				left = 0;
				
			};
			class ShortcutPos
			{
				top = 0;
				left = 0;
				w = 0;
				h = 0;
				
			};
			class TextPos
			{
				top = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2;
				right = 0.005;
				bottom = 0;
				left = 0.25 * (((safezoneW / safezoneH) min 1.2) / 40);
				forcedMiddle = true;
				
			};
			
		};
		class VehiclePylonsFrame
		{
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.29010417;
			y = safeZoneY + safeZoneH * 0.515;
			w = safeZoneW * 0.18229167;
			h = safeZoneH * 0.27851852;
			style = 0+64;
			text = "Loadout";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class VehiclePylonsList
		{
			type = 102;
			idc = VEHICLEPYLONS;
			x = safeZoneX + safeZoneW * 0.29375;
			y = safeZoneY + safeZoneH * 0.53981482;
			w = safeZoneW * 0.175;
			h = safeZoneH * 0.24907408;
			style = 16+32;
			color[] = {1, 1, 1, 1};
			colorBackground[] = {0.9098,0.7619,0.4997,0.8};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelect[] = {1,0,0,1};
			colorText[] = {0.2,0.4,0.4,1};
			colomns[] = {-0.01};
			font = "PuristaMedium";
			maxHistoryDelay = 0;
			rowHeight = 0;
			sizeEx = (((((safezoneW/safezoneH)min 1.2)/1.2)/25)*1);
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
			onLBSelChanged = "params['_control', '_lbCurSel', '_lbSelection'];";
			onLoad = "uiNameSpace setVariable ['VEHICLEPYLONS', _this select 0]; with uiNamespace do{call GES_fnc_loadVehiclePylons}";
			drawSideArrows = 0;	
			idcLeft = -1;
			idcRight = -1;
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class turretSwapButton :ctrlButtonPictureKeepAspect
		{
			idc = TURRETBUTTON;
			x = safeZoneX + safeZoneW * 0.47916667;
			y = safeZoneY + safeZoneH * 0.75092593;
			w = safeZoneW * 0.02135417;
			h = safeZoneH * 0.03796297;
			text = "a3\ui_f\data\IGUI\RscIngameUI\RscUnitInfo\role_driver_ca.paa";
			tooltip = "Turret to be assigned (Driver/Gunner)";
			borderSize = 0;
			colorBackground[] = {0.9098,0.7619,0.4997,1};
			colorBackgroundActive[] = {1,0,0,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {1,1,1,1};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,1};
			colorText[] = {0,0,0,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			shadow = 1;
			onLoad = "with uiNamespace do{TURRETBUTTON = _this select 0; TURRET = [-1]}";
			action = "with uiNameSpace do{if(TURRET isEqualTo [-1])then{TURRETBUTTON ctrlSetText ""a3\ui_f\data\IGUI\RscIngameUI\RscUnitInfo\role_gunner_ca.paa""; TURRET = [0]}else{TURRETBUTTON ctrlSetText ""a3\ui_f\data\IGUI\RscIngameUI\RscUnitInfo\role_driver_ca.paa""; TURRET = [-1]}}";
			
		};
		class ExportSqf
		{
			type = 1;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.6453125;
			y = safeZoneY + safeZoneH * 0.76944445;
			w = safeZoneW * 0.07083334;
			h = safeZoneH * 0.03796297;
			style = 0+2;
			text = "Export for sqf";
			borderSize = 0;
			colorBackground[] = {0.4,0.6,0.4,1};
			colorBackgroundActive[] = {1,0,0,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,1};
			colorText[] = {0.102,0.102,0.102,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			tooltip = "Copy to clipboard bodged loadout for pasting in sqf file";
			action = "with uiNameSpace do{[editingVehicle, true] call GES_fnc_exportLoadOut}";
		};
		class ExportInit
		{
			type = 1;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.6453125;
			y = safeZoneY + safeZoneH * 0.71944445;
			w = safeZoneW * 0.07083334;
			h = safeZoneH * 0.03796297;
			style = 0+2;
			text = "Export for init";
			borderSize = 0;
			colorBackground[] = {0.4,0.6,0.4,1};
			colorBackgroundActive[] = {1,0,0,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,1};
			colorText[] = {0.102,0.102,0.102,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			tooltip = "Copy to clipboard bodged loadout for pasting in init field of vehicle in Eden Editor";
			action = "with uiNameSpace do{[editingVehicle, false] call GES_fnc_exportLoadOut}";
		};
		class SaveLoad
		{
			type = 1;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.52864584;
			y = safeZoneY + safeZoneH * 0.75;
			w = safeZoneW * 0.0875;
			h = safeZoneH * 0.05;
			style = 0+2;
			text = "Save/Load";
			borderSize = 0;
			colorBackground[] = {0.2,0.4,0.2,1};
			colorBackgroundActive[] = {1,0,0,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,1};
			colorText[] = {0.8,0.2,0.2,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			tooltip = "Open save/load loadouts UI";
			action = "with uinamespace do{PYLONUI createDisplay ""GESloadoutMenu""}";
		};	
	};
};
class GESloadoutMenu
{
	onLoad = "with uinamespace do {LOADOUTMENUGROUP = _this select 0}";
	idd = LOADOUTMENUGROUP;
	class VScrollbar
	{
		width = 0;
		color[] = {1,1,1,1};
		autoScrollEnabled = 1;
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
		shadow = 0;
		scrollSpeed = 0.06;
		height = 0;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
	};
	class HScrollbar
	{
		height = 0;
		color[] = {1,1,1,1};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
		shadow = 0;
		scrollSpeed = 0.06;
		width = 0;
		autoScrollEnabled = 0;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
	};
	class ControlsBackground
	{
		class background
		{
			moving = true;
			type = 0;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.29375;
			y = safeZoneY + safeZoneH * 0.225;
			w = safeZoneW * 0.4125;
			h = safeZoneH * 0.55;
			style = 0;
			text = "";
			colorBackground[] = {0.5961,0.7137,0.7569,0.9};
			colorText[] = {0.4039,0.2863,0.2431,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class ListFrame
		{
			type = 0;
			idc = -1;
			x = 0.02398992;
			y = 0.00367004;
			w = 0.96202022;
			h = 0.64279462;
			style = 64;
			text = "Load Outs";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class MenuFrame
		{
			type = 0;
			idc = -1;
			x = -0.0060097;
			y = -0.02632957;
			w = 1.01202022;
			h = 1.03279466;
			style = 64;
			text = "Loadouts For: VEHICLE";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class SearchFrame
		{
			type = 0;
			idc = -1;
			x = 0.06399003;
			y = 0.64367021;
			w = 0.90202022;
			h = 0.14279467;
			style = 64;
			text = "Loadout Search/Set";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
	};
	class Controls
	{
		class LoadOuts
		{
			type = 5;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.3078125;
			y = safeZoneY + safeZoneH * 0.25185186;
			w = safeZoneW * 0.38958334;
			h = safeZoneH * 0.31944445;
			style = 16;
			colorBackground[] = {0.302,0.302,0.302,0.8};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelect[] = {0.9918,0.7804,0,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			maxHistoryDelay = 0;
			rowHeight = 0;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
			class ListScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				
			};
			
		};
		class SearchBar
		{
			type = 2;
			idc = -1;
			x = 0.0719697;
			y = 0.6834007;
			w = 0.88005053;
			h = 0.0909091;
			style = 0;
			text = "Loadout Name";
			autocomplete = "";
			colorBackground[] = {0.8275,0.7608,0.6471,0.8};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorSelection[] = {1,0,0,1};
			colorText[] = {0.1725,0.2392,0.3529,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class loadButton
		{
			type = 1;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.52135417;
			y = safeZoneY + safeZoneH * 0.68796297;
			w = safeZoneW * 0.12552084;
			h = safeZoneH * 0.05925926;
			style = 0+1+2;
			text = "Load";
			borderSize = 0;
			colorBackground[] = {0.102,0.2,0.6,1};
			colorBackgroundActive[] = {1,0,0,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,1};
			colorText[] = {0.898,0.9333,0.6706,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class saveButton
		{
			type = 1;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.33333334;
			y = safeZoneY + safeZoneH * 0.68796297;
			w = safeZoneW * 0.12552084;
			h = safeZoneH * 0.05925926;
			style = 0+2;
			text = "Save";
			borderSize = 0;
			colorBackground[] = {0.102,0.302,0.102,1};
			colorBackgroundActive[] = {1,0,0,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,1};
			colorText[] = {0.898,0.9333,0.6706,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};	
		};
		
	};
};
