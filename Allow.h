#pragma once
//#include "FCF_1_0.hpp"
#include <uf_defs.h>
#include <uf_ui_types.h>
#include <iostream>
#include <NXOpen/Session.hxx>
#include <NXOpen/UI.hxx>
#include <NXOpen/NXMessageBox.hxx>
#include <NXOpen/Callback.hxx>
#include <NXOpen/NXException.hxx>
#include <NXOpen/BlockStyler_UIBlock.hxx>
#include <NXOpen/BlockStyler_BlockDialog.hxx>
#include <NXOpen/BlockStyler_PropertyList.hxx>
#include <NXOpen/BlockStyler_Group.hxx>
#include <NXOpen/BlockStyler_StringBlock.hxx>



#include <uf_defs.h>
#include <NXOpen/NXException.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/Annotations_Annotation.hxx>
#include <NXOpen/Annotations_AnnotationManager.hxx>
#include <NXOpen/Annotations_BreakSettingsBuilder.hxx>
#include <NXOpen/Annotations_CompoundDatumReferenceBuilder.hxx>
#include <NXOpen/Annotations_DatumReferenceBuilder.hxx>
#include <NXOpen/Annotations_DatumReferenceBuilderList.hxx>
#include <NXOpen/Annotations_DimensionStyleBuilder.hxx>
#include <NXOpen/Annotations_DraftingFeatureControlFrameBuilder.hxx>
#include <NXOpen/Annotations_FeatureControlFrameBuilder.hxx>
#include <NXOpen/Annotations_FeatureControlFrameDataBuilder.hxx>
#include <NXOpen/Annotations_FeatureControlFrameDataBuilderList.hxx>
#include <NXOpen/Annotations_ForeshorteningSymbolBuilder.hxx>
#include <NXOpen/Annotations_ForeshorteningSymbolSettingsBuilder.hxx>
#include <NXOpen/Annotations_FrameBarElementStyleBuilder.hxx>
#include <NXOpen/Annotations_FrameBarStyleBuilder.hxx>
#include <NXOpen/Annotations_HatchStyleBuilder.hxx>
#include <NXOpen/Annotations_HoleCalloutSettingsBuilder.hxx>
#include <NXOpen/Annotations_LeaderBuilder.hxx>
#include <NXOpen/Annotations_LeaderData.hxx>
#include <NXOpen/Annotations_LeaderDataList.hxx>
#include <NXOpen/Annotations_LetteringStyleBuilder.hxx>
#include <NXOpen/Annotations_LineArrowStyleBuilder.hxx>
#include <NXOpen/Annotations_OrdinateStyleBuilder.hxx>
#include <NXOpen/Annotations_OriginBuilder.hxx>
#include <NXOpen/Annotations_PlaneBuilder.hxx>
#include <NXOpen/Annotations_RadialStyleBuilder.hxx>
#include <NXOpen/Annotations_SingleSidedDisplayBuilder.hxx>
#include <NXOpen/Annotations_StyleBuilder.hxx>
#include <NXOpen/Annotations_SymbolStyleBuilder.hxx>
#include <NXOpen/Annotations_TextWithSymbolsBuilder.hxx>
#include <NXOpen/Annotations_UnitsStyleBuilder.hxx>
#include <NXOpen/Builder.hxx>
#include <NXOpen/DisplayableObject.hxx>
#include <NXOpen/Drawings_DraftingView.hxx>
#include <NXOpen/Drawings_SelectDraftingView.hxx>
#include <NXOpen/NXObject.hxx>
#include <NXOpen/ObjectList.hxx>
#include <NXOpen/Part.hxx>
#include <NXOpen/PartCollection.hxx>
#include <NXOpen/SelectDisplayableObject.hxx>
#include <NXOpen/SelectDisplayableObjectList.hxx>
#include <NXOpen/SelectObject.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/Xform.hxx>
#include <NXOpen/Annotations_FeatureControlFrameBuilder.hxx>

#include <NXOpen/NXColor.hxx>
#include <uf_udobj.h>
#include <uf_disp.h>
#include <uf_drf.h>
#include <uf_text.h>



#include <uf_defs.h>
#include <NXOpen/NXException.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/Annotations_Annotation.hxx>
#include <NXOpen/Annotations_AnnotationManager.hxx>
#include <NXOpen/Annotations_BaseCustomSymbolBuilder.hxx>
#include <NXOpen/Annotations_BreakSettingsBuilder.hxx>
#include <NXOpen/Annotations_CustomSymbol.hxx>
#include <NXOpen/Annotations_CustomSymbolCollection.hxx>
#include <NXOpen/Annotations_DimensionStyleBuilder.hxx>
#include <NXOpen/Annotations_DraftingCustomSymbolBuilder.hxx>
#include <NXOpen/Annotations_DraftingNoteBuilder.hxx>
#include <NXOpen/Annotations_ForeshorteningSymbolBuilder.hxx>
#include <NXOpen/Annotations_ForeshorteningSymbolSettingsBuilder.hxx>
#include <NXOpen/Annotations_FrameBarElementStyleBuilder.hxx>
#include <NXOpen/Annotations_FrameBarStyleBuilder.hxx>
#include <NXOpen/Annotations_HatchStyleBuilder.hxx>
#include <NXOpen/Annotations_HoleCalloutSettingsBuilder.hxx>
#include <NXOpen/Annotations_LeaderBuilder.hxx>
#include <NXOpen/Annotations_LeaderData.hxx>
#include <NXOpen/Annotations_LeaderDataList.hxx>
#include <NXOpen/Annotations_LetteringStyleBuilder.hxx>
#include <NXOpen/Annotations_LineArrowStyleBuilder.hxx>
#include <NXOpen/Annotations_MasterSymbolListItemBuilder.hxx>
#include <NXOpen/Annotations_MasterSymbolListItemBuilderList.hxx>
#include <NXOpen/Annotations_OrdinateStyleBuilder.hxx>
#include <NXOpen/Annotations_OriginBuilder.hxx>
#include <NXOpen/Annotations_PlaneBuilder.hxx>
#include <NXOpen/Annotations_RadialStyleBuilder.hxx>
#include <NXOpen/Annotations_SingleSidedDisplayBuilder.hxx>
#include <NXOpen/Annotations_StyleBuilder.hxx>
#include <NXOpen/Annotations_SymbolStyleBuilder.hxx>
#include <NXOpen/Annotations_TextWithEditControlsBuilder.hxx>
#include <NXOpen/Annotations_TextWithSymbolsBuilder.hxx>
#include <NXOpen/Annotations_UnitsStyleBuilder.hxx>
#include <NXOpen/Builder.hxx>
#include <NXOpen/DisplayableObject.hxx>
#include <NXOpen/Drawings_DraftingView.hxx>
#include <NXOpen/Drawings_SelectDraftingView.hxx>
#include <NXOpen/Expression.hxx>
#include <NXOpen/NXObject.hxx>
#include <NXOpen/ObjectList.hxx>
#include <NXOpen/Part.hxx>
#include <NXOpen/PartCollection.hxx>
#include <NXOpen/SelectDisplayableObject.hxx>
#include <NXOpen/SelectDisplayableObjectList.hxx>
#include <NXOpen/SelectObject.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/Unit.hxx>
#include <NXOpen/Xform.hxx>

#include <uf_ui.h>
#include <uf_obj.h>
#include <uf_vec.h>
#include <uf_mtx.h>
#include <uf_csys.h>
#include <uf_modl.h>
#include <uf.h>
#include <uf_modl_legacy.h>
#include <uf_mtx.h>
using namespace NXOpen;
/*#include <stdio.h>
#include <string.h>
#include <uf.h>
#include <uf_defs.h>
#include <uf_drf.h>
#include <uf_curve.h>
#include <uf_csys.h>


#include <uf_ui.h>
#include <uf_obj.h>
#include <uf.h>
#include <uf_mtx.h>*/

typedef struct
{
    UF_CURVE_arc_t* arc;
    double          abs_ctr[3];
    double          matrix[9];
    double          x_axis[3];
    double          y_axis[3];
} my_motion_data_t;



void motion_cb(double* screen_pos,
    UF_UI_motion_cb_data_p_t  motion_cb_data,
    my_motion_data_t* my_data);

void size_string(int count,
    NXOpen::NXString enum_Characteristic,
    NXOpen::NXString enum_Style,
    NXOpen::NXString enum0,
    NXOpen::NXString enum01 );

void create_allow_udo
(
	NXOpen::NXString enum_Characteristic,
    NXOpen::NXString enum_Style,
    NXOpen::NXString enum0,
    NXOpen::NXString string_Allow,
    NXOpen::NXString enum01,
    bool toggle_FreeState,
    bool toggle_TangentPlane,
    bool toggle_Projected,
    NXOpen::NXString string_Projected,
    bool toggle_CircleU,
    NXOpen::NXString string_CircleU,
    bool toggle_Statistical,
    bool toggle_CommonArea,
    bool toggle_Max,
    NXOpen::NXString string_Max,
    double* arc_edge_pos
);
void create_allow();
