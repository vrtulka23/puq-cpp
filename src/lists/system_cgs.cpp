#import "lists.h"

#ifdef UNIT_SYSTEM_CGS

namespace puq {namespace SystemData {

  const UnitListType _CGS_UNITS = { 
    {"Gal",      {Utype::LIN,     "cm/s2",                  "Gal",               false, {}             }},
    {"dyn",      {Utype::LIN,     "g*cm/s2",                "dyne",              true,  {}             }},
    {"Ba",       {Utype::LIN,     "dyn/cm2",                "Barye",             false, {}             }},
    {"b",        {Utype::LIN,     "Ba",                     "Barye",             false, {}             }},
    {"erg",      {Utype::LIN,     "dyn*cm",                 "erg",               false, {}             }},
    {"St",       {Utype::LIN,     "cm2/s",                  "Stokes",            true,  {"c"}          }},
    {"P",        {Utype::LIN,     "g/(cm*s)",               "Poise",             true,  {"c"}          }},
    {"Ka",       {Utype::LIN,     "cm-1",                   "Kayser",            false, {}             }},
    {"Pma",      {Utype::LIN,     "1e-4*m2",                "permeability",      false, {}             }},
    {"Rayl",     {Utype::LIN,     "g/(cm2*s)",              "Rayl",              false, {}             }},
    {"radd",     {Utype::LIN,     "100*erg/g",              "radiation dose",    false, {"d","h","k","M"} }},
    // constants
    {"[m_u]",    {Utype::CST,     "1.660539069e-24*g",      "atom. mass const.", false, {}             }},    
    {"[a_0]",    {Utype::CST,     "5.291772105e-9*cm",      "Bohr radius",       false, {}             }},    
    {"[k]",      {Utype::CST,     "1.380649e-16*erg/K",     "Boltzmann const.",  false, {}             }},    
    {"[m_e]",    {Utype::CST,     "9.10938371e-28*g",       "electron mass",     false, {}             }},    
    {"[alpha]",  {Utype::CST,     "0.007297352564",         "fine-str. const.",  false, {}             }},    
    {"[G]",      {Utype::CST,     "6.6743e-8*dyn*cm2/g2",   "gravit. const.",    false, {}             }},    
    {"[h]",      {Utype::CST,     "6.62607015e-27*erg*s",   "Planck const.",     false, {}             }},    
    {"[hbar]",   {Utype::CST,     "1.054571817e-27*erg*s",  "reduced Pl. con.",  false, {}             }},    
    {"[c]",      {Utype::CST,     "2.99792458e10*cm/s",     "speed of light",    false, {}             }},    
    {"[c_0]",    {Utype::CST,     "2.99792458e10",          "num. speed of li.", false, {}             }},    
    {"[pi]",     {UT_LIN_CST,     "3.1415926",              "pi num.",           false, {}             }},
  };

  const QuantityListType _CGS_QUANTITIES = {
    {"l",       {"cm"       }},
    {"m",       {"g"        }},    
    {"t",       {"s"        }},
    {"Iv",      {"cd"       }},
    {"n",       {"mol"      }},
    {"the",     {"rad"      }},
    // mechanics
    {"v",       {"cm/s"     }},
    {"a",       {"Gal"      }},
    {"F",       {"dyn"      }},
    {"E",       {"erg"      }},
    {"P",       {"erg/s"    }},
    {"p",       {"Ba"       }},
    {"mu_v",    {"P"        }},
    {"nu_v",    {"St"       }},
    {"k_n",     {"Ka"       }},
  };
    
  const UnitListType _GAUSS_ESU_UNITS = {
    {"Fr",       {Utype::LIN,     "dyn1:2*cm",           "franklin",             false, {}             }},
    {"statC",    {Utype::LIN,     "Fr",                  "Statcoulomb",          false, {}             }},
    {"esu",      {Utype::LIN,     "Fr",                  "elstat. u.o. charge",  false, {}             }},
    {"statA",    {Utype::LIN,     "Fr/s",                "Statampere",           false, {}             }},
    {"statV",    {Utype::LIN,     "erg/Fr",              "Statvolt",             false, {}             }},
    {"statOhm",  {Utype::LIN,     "s/cm",                "Statohm",              false, {}             }},
    {"statF",    {Utype::LIN,     "cm",                  "Statfarad",            false, {}             }},
    {"statH",    {Utype::LIN,     "s2/cm",               "Stathenry",            false, {}             }},
    // constants 										      
    {"[e]",      {Utype::CST,     "4.80320471e-10*Fr",   "elementary charge",    false, {}             }},
  };
    
  const QuantityListType _GAUSS_ESU_QUANTITIES = {
    {"q",       {"statC",        "1e1/[c_0]"              }},
    {"I",       {"statA",        "1e1/[c_0]"              }},
    {"phi_e",   {"statV",        "1e-8*[c_0]"             }},
    {"E_e",     {"statV/cm",     "1e-6*[c_0]"             }},
    {"D_e",     {"statC/cm2",    "1e5/(4*[pi]*[c_0])"     }},
    {"p_e",     {"statC*cm",     "1e-1/[c_0]"             }},
    {"Phi_E",   {"statC",        "1e1/(4*[pi]*[c_0])"     }},
    {"eps",     {"1",            "1e11/(4*[pi]*[c_0]2)"   }},
    {"R",       {"statOhm",      "[c_0]2/1e9"             }},
    {"rho_e",   {"statOhm*cm",   "[c_0]2/1e11"            }},
    {"C",       {"statF",        "1e9/[c_0]2"             }},
    {"L",       {"statH",        "[c_0]2/1e9"             }},
  };

  SystemDataType ESU = {
    "ESU", "Electrostatic CGS units", 
    _BASE_UNITS + _CGS_UNITS + _GAUSS_ESU_UNITS + UnitListType({
	{"statT",    {Utype::LIN,     "cm-3:2*g1:2",                 "Stattesla",     false, {}             }},
	{"statWb",   {Utype::LIN,     "cm2*g",                       "Statweber",     false, {}             }},
	// constants     											    
	{"[mu_B]",   {Utype::CST,     "2.780278273e-10*statA*cm2 ",  "Bohr magneton", false, {}             }},
      }),
    _CGS_QUANTITIES + _GAUSS_ESU_QUANTITIES + QuantityListType({
	{"B",      {"statT",       "1e-4*[c_0]"           }},
	{"H",      {"statA/cm",    "1e3/(4*[pi]*[c_0])"   }},
	{"mm",     {"statA*cm2",   "1e-3/[c_0]"           }},
	{"Phi_M",  {"statWb",      "[c_0]*1e-8"           }},
	{"mu",     {"s2/cm2",      "4*[pi]*[c_0]2*1e-7"   }},
      }),
    DimensionMapType({
#ifdef MAGNITUDE_ERRORS
#include "dmaps/dmap_ESU_err.h"
#else
#include "dmaps/dmap_ESU.h"
#endif
      })
  };
  
  const UnitListType _GAUSS_EMU_UNITS = {
    {"G",        {Utype::LIN,    "cm-1:2*g1:2*s-1",        "Gauss",             false, {}             }},
    {"Oe",       {Utype::LIN,    "g1:2/(cm1:2*s)",         "Oersted",           false, {}             }},
    {"Gb",       {Utype::LIN,    "Oe*cm",                  "Gilbert",           false, {}             }},
    {"Mx",       {Utype::LIN,    "dyn1:2*cm2",             "Maxwell",           false, {}             }},
    // constants 										     
    {"[mu_B]",   {Utype::CST,    "9.274010066e-21*erg/G",  "Bohr magneton",     false, {}             }},
  };

  const QuantityListType _GAUSS_EMU_QUANTITIES = {
    {"B",      {"G",           "1e-4"           }},
    {"H",      {"Oe",          "1e3/(4*[pi])"   }},
    {"mm",     {"erg/G",       "1e-3"           }},
    {"Phi_M",  {"Mx",          "1e-8"           }},
    {"mu",     {"1",           "4*[pi]*1e-7"    }},
  };
    
  SystemDataType GAUSS = {
    "GAUSS", "Gaussian CGS units", 
    _BASE_UNITS + _CGS_UNITS + _GAUSS_ESU_UNITS + _GAUSS_EMU_UNITS,
    _CGS_QUANTITIES + _GAUSS_ESU_QUANTITIES + _GAUSS_EMU_QUANTITIES,
    DimensionMapType({
#ifdef MAGNITUDE_ERRORS
#include "dmaps/dmap_GAUSS_err.h"
#else
#include "dmaps/dmap_GAUSS.h"
#endif
      })
  };
  
  SystemDataType EMU = {
    "EMU", "Electromagnetic CGS units",
    _BASE_UNITS + _CGS_UNITS + _GAUSS_EMU_UNITS + UnitListType({
        {"Bi",       {Utype::LIN,     "dyn1:2",              "biot",                 false, {}             }},
        {"abA",      {Utype::LIN,     "Bi",                  "Abampere",             false, {}             }},
        {"abC",      {Utype::LIN,     "Bi*s",                "Abcoulomb",            false, {}             }},
        {"aC",       {Utype::LIN,     "abC",                 "Abcoulomb",            false, {}             }},
        {"abV",      {Utype::LIN,     "g1:2*cm3:2*s-2",      "Abvolt",               false, {}             }},
        {"abOhm",    {Utype::LIN,     "cm*s",                "Abohm",                false, {}             }},
        {"abF",      {Utype::LIN,     "cm-1*s2",             "Abfarad",              false, {}             }},
        {"abH",      {Utype::LIN,     "cm",                  "Abhenry",              false, {}             }},
        // constants	   											 
        {"[e]",      {Utype::CST,     "1.602176634e-20*abC", "elementary charge",    false, {}             }},
      }),
    _CGS_QUANTITIES + _GAUSS_EMU_QUANTITIES + QuantityListType({
	{"q",       {"abC",        "1e1"              }},
	{"I",       {"abA",        "1e1"              }},
	{"phi_e",   {"abV",        "1e-8"             }},
	{"E_e",     {"abV/cm",     "1e-6"             }},
	{"D_e",     {"abC/cm2",    "1e5/(4*[pi])"     }},
	{"p_e",     {"abC*cm",     "1e-1"             }},
	{"Phi_E",   {"abC",        "1e1/(4*[pi])"     }},
	{"eps",     {"s2/cm2",     "1e11/(4*[pi])"    }},
	{"R",       {"abOhm",      "1e-9"             }},
	{"rho_e",   {"abOhm*cm",   "1e-11"            }},
	{"C",       {"abF",        "1e9"              }},
	{"L",       {"abH",        "1e-9"             }},
      }),
    DimensionMapType({
#ifdef MAGNITUDE_ERRORS
#include "dmaps/dmap_EMU_err.h"
#else
#include "dmaps/dmap_EMU.h"
#endif
      })
  };
  
}}

#endif // UNIT_SYSTEM_CGS
