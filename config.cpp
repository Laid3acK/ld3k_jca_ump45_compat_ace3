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
    class B_45ACP_Ball;
    class JCA_B_45ACP_Ball: B_45ACP_Ball // Winchester Law Enforcement .45 ACP +P 230gr, 990fps (302m/s) barrel length 5" https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
    {
        ACE_caliber=11.48; // CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/45-auto-en-1.pdf
        ACE_bulletLength=16.99; // 0.669"
        ACE_bulletMass=14.904; // 230gr
        ACE_ammoTempMuzzleVelocityShifts[]={-1.87,-1.82,-1.66,-1.4,-1.04,-0.57,0,0.68,1.46,2.34,3.33}; // Same curve default ACE_ammoTempMuzzleVelocityShifts, values /10. Muzzle velocity shift 0 m/s ICAO conditions (15°C, 1013.25hPa, 0%)
        ACE_ballisticCoefficients[]={0.193}; // calculated from https://winchesterle.com/Ammunition/Products/Handgun/Ranger-T-Series/RA45TP
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={278,302,344}; // 332m/s barrel length 200mm ICAO conditions (15°C, 1013.25 hPa, 0%)
        ACE_barrelLengths[]={101.6,127,228.6}; // 4", 5", 9"
        visibleFire=1; // Subsonic, B_127x54_Ball, BulletBase 3
        audibleFire=5; // Subsonic, B_127x54_Ball, B_45ACP_Ball 45
        typicalSpeed=302; // B_45ACP_Ball 280
        airFriction=-0.00109195; // airFrictionAnalysis.txt in docs folder
    };
};
class CfgMagazines
{
    class CA_Magazine;
    class JCA_25Rnd_45ACP_UMP_Mag: CA_Magazine
    {
        mass=15.3; // Operators Manual UMP45 empty magazine 25rnd 170g + cartridge 21g x25= 695g
        initSpeed=332; // according to ACE_muzzleVelocities UMP45 barrel 200mm ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_25Rnd_45ACP_UMP_Red_Mag: JCA_25Rnd_45ACP_UMP_Mag
    {
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag: JCA_25Rnd_45ACP_UMP_Red_Mag
    {
        displaynameshort="Tracer";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_IR_Mag: JCA_25Rnd_45ACP_UMP_Tracer_Red_Mag
    {
        displaynameshort="Tracer IR";
    };
    class JCA_25Rnd_45ACP_UMP_Sand_Mag: JCA_25Rnd_45ACP_UMP_Mag
    {
    };
    class JCA_25Rnd_45ACP_UMP_Red_Sand_Mag: JCA_25Rnd_45ACP_UMP_Sand_Mag
    {
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag: JCA_25Rnd_45ACP_UMP_Red_Sand_Mag
    {
        displaynameshort="Tracer";
    };
    class JCA_25Rnd_45ACP_UMP_Tracer_IR_Sand_Mag: JCA_25Rnd_45ACP_UMP_Tracer_Red_Sand_Mag
    {
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
        ACE_RailHeightAboveBore=4.84595;  // from ACE3 checkScopes.sqf
        ACE_barrelLength=200; // Operators Manual UMP45
        ACE_barrelTwist=406; // Operators Manual UMP45 https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/45-auto-en-1.pdf
        initSpeed=-1; // 332m/s, 200mm barrel length, according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 300
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=49.8; // Operators Manual UMP45 2.26kg w/o magazine
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.0016; // 9.82 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0009 (3.09 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.0016; // 9.82 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.0009 (3.09 MOA)
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
        ACE_ScopeHeightAboveRail=4.48261; // from ACE3 checkScopes.sqf
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
