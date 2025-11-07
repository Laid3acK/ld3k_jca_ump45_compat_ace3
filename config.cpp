class CfgPatches
{
    class ld3k_jca_ump45_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_UMP",
            "Weapons_F_JCA_UMP_Accessories",
            "Weapons_F_JCA_UMP_SMGs_UMP"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    class BulletBase;
    /*class B_45ACP_Ball: BulletBase // official BI tool All-in-one Config Arma3 2.19.152743 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        airLock=1;
        hit=5;
        indirectHit=0;
        indirectHitRange=0;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
        cartridge="FxCartridge_9mm";
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
        caliber=1.4;
        deflecting=25;
        audibleFire=45;
        cost=100;
        typicalSpeed=280;
        airFriction=-0.0018;
        tracerScale=0.6;
        tracerStartTime=0.0075;
        tracerEndTime=5;
    };
    class B_45ACP_Ball_Green: B_45ACP_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class B_45ACP_Ball_Yellow: B_45ACP_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class B_45ACP_Ball: BulletBase // ACE3 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L727
    {
        airFriction=-0.00082143;
        tracerScale=0.6;
        ACE_caliber=11.481;
        ACE_bulletLength=17.272;
        ACE_bulletMass=14.904;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619};
        ACE_ballisticCoefficients[]={0.195};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={230,250,285};
        ACE_barrelLengths[]={101.6,127.0,228.6};
    };*/
    class JCA_B_45ACP_Ball_UMP45: BulletBase // Winchester Law Enforcement .45 ACP +P 230gr, 990fps (302m/s) barrel length 5" https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
    {
        ACE_caliber=11.48; // CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/45-auto-en-1.pdf
        ACE_bulletLength=16.99; // 0.669"
        ACE_bulletMass=14.904; // 230gr
        ACE_ammoTempMuzzleVelocityShifts[]={-1.87,-1.82,-1.66,-1.4,-1.04,-0.57,0,0.68,1.46,2.34,3.33}; // Same curve default ACE_ammoTempMuzzleVelocityShifts, values /10. Muzzle velocity shift 0m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        // ACE_ballisticCoefficients[]={0.193}; // 990fps (302m/s) 5", ICAO G1 BC from exterior ballistic app "EBC V2" based on https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        // ACE_standardAtmosphere="ICAO";
        // ACE_ballisticCoefficients[]={0.187}; // 990fps (302m/s) 5", ASM G1 BC from exterior ballistic app "EBC V2" based on https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        // ACE_standardAtmosphere="ASM";
        ACE_ballisticCoefficients[]={0.261}; // 1089fps (332m/s) 200mm, ICAO G1 BC from exterior ballistic app "EBC V2" based on https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        ACE_standardAtmosphere="ICAO";
        // ACE_ballisticCoefficients[]={0.254}; // 1089fps (332m/s) 200mm, ASM G1 BC from exterior ballistic app "EBC V2" based on https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        // ACE_standardAtmosphere="ASM";
        ACE_velocityBoundaries[]={};
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={278,302,344}; // 332m/s barrel length 200mm ICAO conditions (15°C, 1013.25 hPa, 0%)
        ACE_barrelLengths[]={101.6,127,228.6}; // 4", 5", 9"
        airLock=1;
        hit=7; // 822 Joules, B_45ACP_Ball 5 584 Joules, JCA
        indirectHit=0;
        indirectHitRange=0;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
        cartridge="FxCartridge_9mm";
        model="\A3\Weapons_f\Data\bullettracer\tracer_white"; // B_45ACP_Ball tracer_red
        caliber=1.4;
        deflecting=25;
        visibleFire=1; // Subsonic, B_127x54_Ball, BulletBase 3
        audibleFire=5; // Subsonic, B_127x54_Ball, B_45ACP_Ball 45
        cost=100;
        typicalSpeed=332; // 822 Joules, B_45ACP_Ball 280 584 Joules
        airFriction=-0.00096737; // airFrictionAnalysis.txt in docs folder
        tracerScale=0.6;
        tracerStartTime=0.0075;
        tracerEndTime=5;
        nvgOnly=0; // B_45ACP_Ball w/o nvgOnly
    };
    class JCA_B_45ACP_Ball_UMP45_Tracer_Red: JCA_B_45ACP_Ball_UMP45
    {
        visibleFire=5; // B_45ACP_Ball 3, B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_45ACP_Ball_UMP45_Tracer_Green: JCA_B_45ACP_Ball_UMP45_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_45ACP_Ball_UMP45_Tracer_Yellow: JCA_B_45ACP_Ball_UMP45_Tracer_Red
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class JCA_B_45ACP_Ball_UMP45_Tracer_IR: JCA_B_45ACP_Ball_UMP45
    {
        nvgOnly=1;
    };
};
class CfgMagazines
{
    class CA_Magazine;
    class JCA_25Rnd_45ACP_UMP_Mag: CA_Magazine // JCA default config
    {
        // mass=15.3; // Operators Manual UMP45 empty magazine 25rnd 170g + cartridge 21g x25= 695g, 30Rnd_45ACP_Mag_SMG_01 10, JCA 10
        ammo="JCA_B_45ACP_Ball_UMP45";
        initSpeed=332; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 370
    };
    class JCA_25Rnd_45ACP_UMP_Red_Mag: JCA_25Rnd_45ACP_UMP_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Red";
    };
    class JCA_25Rnd_45ACP_UMP_Green_Mag: JCA_25Rnd_45ACP_UMP_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Green";
    };
    class JCA_25Rnd_45ACP_UMP_Yellow_Mag: JCA_25Rnd_45ACP_UMP_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Yellow";
    };
    class JCA_25Rnd_45ACP_UMP_IR_Mag: JCA_25Rnd_45ACP_UMP_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_IR";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag: JCA_25Rnd_45ACP_UMP_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_Green_Mag: JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Green";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Mag: JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Yellow";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_IR_Mag: JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_25Rnd_45ACP_UMP_Sand_Mag: JCA_25Rnd_45ACP_UMP_Mag
    {
    };
    class JCA_25Rnd_45ACP_UMP_Red_Sand_Mag: JCA_25Rnd_45ACP_UMP_Sand_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Red";
    };
    class JCA_25Rnd_45ACP_UMP_Green_Sand_Mag: JCA_25Rnd_45ACP_UMP_Red_Sand_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Green";
    };
    class JCA_25Rnd_45ACP_UMP_Yellow_Sand_Mag: JCA_25Rnd_45ACP_UMP_Red_Sand_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Yellow";
    };
    class JCA_25Rnd_45ACP_UMP_IR_Sand_Mag: JCA_25Rnd_45ACP_UMP_Red_Sand_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_IR";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag: JCA_25Rnd_45ACP_UMP_Red_Sand_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_Green_Sand_Mag: JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Green";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Sand_Mag: JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_Yellow";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_IR_Sand_Mag: JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag
    {
        ammo="JCA_B_45ACP_Ball_UMP45_Tracer_IR";
        displaynameshort="Tracer IR";
    };
};
class CfgMagazineWells
{
    class JCA_UMP_45ACP // Weapon initSpeed -1 ACE_barrelLength 200mm: 332m/s ICAO conditions (15°C, 1013.25 hPa, 0%) according to JCA_25Rnd_45ACP_UMP magazines initSpeed
    {
        JCA_Magazines[]=
        {
            "JCA_25Rnd_45ACP_UMP_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Mag",
            "JCA_25Rnd_45ACP_UMP_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Sand_Mag"
        };
    };
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
    class InventoryMuzzleItem_Base_F;
    class ItemCore;
    class Rifle_Base_F;
    class Rifle_Short_Base_F: Rifle_Base_F
    {
        class WeaponSlotsInfo;
    };
    class JCA_smg_UMP_base_F: Rifle_Short_Base_F
    {
        ACE_RailHeightAboveBore=4.84595; // ACE3 checkScopes.sqf
        ACE_barrelLength=200; // Operators Manual UMP45
        ACE_barrelTwist=406; // Operators Manual UMP45 https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/45-auto-en-1.pdf
        maxZeroing=300; // distance .45 ACP 230gr Mach 0.8 (272m/s) ICAO, JCA 400, SMG_01_F (Vermin SMG) 400
        initSpeed=-1; // 332m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 300
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=49.8; // Operators Manual UMP45 2.26kg w/o magazine, JCA 45
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.001186; // 7.25 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0009 (3.09 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.001186; // 7.25 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0009 (3.09 MOA)
        };
        magazines[]=
        {
            "JCA_25Rnd_45ACP_UMP_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Mag",
            "JCA_25Rnd_45ACP_UMP_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Sand_Mag"
        };
    };
    class JCA_smg_UMP_AFG_base_F: JCA_smg_UMP_base_F
    {
    };
    class JCA_smg_UMP_VFG_base_F: JCA_smg_UMP_base_F
    {
    };
    class JCA_smg_UMP_sand_F: JCA_smg_UMP_base_F
    {
        magazines[]=
        {
            "JCA_25Rnd_45ACP_UMP_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Mag"
        };
    };
    class JCA_smg_UMP_AFG_sand_F: JCA_smg_UMP_AFG_base_F
    {
        magazines[]=
        {
            "JCA_25Rnd_45ACP_UMP_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Mag"
        };
    };
    class JCA_smg_UMP_VFG_sand_F: JCA_smg_UMP_VFG_base_F
    {
        magazines[]=
        {
            "JCA_25Rnd_45ACP_UMP_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Sand_Mag",
            "JCA_25Rnd_45ACP_UMP_Mag",
            "JCA_25Rnd_45ACP_UMP_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_IR_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Green_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_Yellow_Mag",
            "JCA_25Rnd_45ACP_UMP_Tracer_IR_Mag"
        };
    };
    class JCA_optic_MROS_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=4.48749; // ACE3 checkScopes.sqf
    };
    class JCA_optic_MROS_base_magnifier: ItemCore
    {
        ACE_ScopeHeightAboveRail=4.48749; // ACE3 checkScopes.sqf
    };
    class JCA_optic_MROS_base_magnifier_UP: ItemCore
    {
        ACE_ScopeHeightAboveRail=4.48749; // ACE3 checkScopes.sqf
    };
    class JCA_muzzle_snds_tactical_base: ItemCore
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class JCA_muzzle_snds_45_tactical_black: JCA_muzzle_snds_tactical_base // Sound Suppressor .45 ACP, muzzle_snds_acp
    {
        class ItemInfo: ItemInfo
        {
            mass=8.4; // Sound Suppressor (B&T) 380g, Operators Manual UMP45
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_acp 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_acp 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_acp 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_acp 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_acp, JCA 0.2, muzzle_snds_H 0.2
    };
    class JCA_muzzle_snds_45_tactical_sand: JCA_muzzle_snds_tactical_base // Sound Suppressor .45 ACP, muzzle_snds_acp
    {
        class ItemInfo: ItemInfo
        {
            mass=8.4; // Sound Suppressor (B&T) 380g, Operators Manual UMP45
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_acp 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_acp 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_acp 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_acp 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_acp, JCA 0.2, muzzle_snds_H 0.2
    };
    class JCA_muzzle_snds_45_tactical_olive: JCA_muzzle_snds_tactical_base // Sound Suppressor .45 ACP, muzzle_snds_acp
    {
        class ItemInfo: ItemInfo
        {
            mass=8.4; // Sound Suppressor (B&T) 380g, Operators Manual UMP45
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_acp 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_acp 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_acp 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_acp 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_acp, JCA 0.2, muzzle_snds_H 0.2
    };
    class muzzle_snds_H: ItemCore // Sound Suppressor 6.5mm
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class muzzle_snds_acp: muzzle_snds_H // Sound Suppressor .45 ACP
    {
        class ItemInfo: ItemInfo
        {
            // mass=6;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_acp 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_acp 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_acp 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_acp 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.1;
    };
};
