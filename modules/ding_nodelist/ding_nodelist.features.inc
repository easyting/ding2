<?php
/**
 * @file
 * ding_nodelist.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ding_nodelist_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ding_nodelist_image_default_styles() {
  $styles = array();

  // Exported image style: ding_nodelist_extra_medium.
  $styles['ding_nodelist_extra_medium'] = array(
    'name' => 'ding_nodelist_extra_medium',
    'label' => 'ding_nodelist_extra_medium',
    'effects' => array(
      4 => array(
        'label' => 'Manual Crop: Custom crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 760,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'ding_nodelist_extra_medium',
        ),
        'weight' => 0,
      ),
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 760,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 760,
          'height' => 562,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ding_nodelist_large.
  $styles['ding_nodelist_large'] = array(
    'name' => 'ding_nodelist_large',
    'label' => 'ding_nodelist_large',
    'effects' => array(
      7 => array(
        'label' => 'Manual Crop: Custom crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1160,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'ding_nodelist_large',
        ),
        'weight' => 0,
      ),
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1160,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1160,
          'height' => 860,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ding_nodelist_medium.
  $styles['ding_nodelist_medium'] = array(
    'name' => 'ding_nodelist_medium',
    'label' => 'ding_nodelist_medium',
    'effects' => array(
      10 => array(
        'label' => 'Manual Crop: Custom crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 560,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'ding_nodelist_medium',
        ),
        'weight' => 0,
      ),
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 560,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 392,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ding_nodelist_medium_reused.
  $styles['ding_nodelist_medium_reused'] = array(
    'name' => 'ding_nodelist_medium_reused',
    'label' => 'ding_nodelist_medium_reused',
    'effects' => array(
      12 => array(
        'label' => 'Manual Crop: Automatically reuse cropped style',
        'help' => 'Load the first applied crop selection and reuse it.',
        'effect callback' => 'manualcrop_auto_reuse_effect',
        'form callback' => 'manualcrop_auto_reuse_form',
        'summary theme' => 'manualcrop_auto_reuse_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_auto_reuse',
        'data' => array(
          'style_priority' => array(
            0 => 'ding_nodelist_medium',
            1 => 'ding_nodelist_small',
            2 => 'ding_nodelist_pn_small',
            3 => 'ding_tabroll_large',
            4 => 'ting_cover_large',
            5 => 'ting_cover_small',
            6 => 'ting_cover_medium',
            7 => 'ding_nodelist_pn_medium',
            8 => 'ding_nodelist_pn_large',
            9 => 'ding_primary_large',
            10 => 'ding_panorama_primary_large',
            11 => 'ding_nodelist_extra_medium',
            12 => 'ding_nodelist_large',
            13 => 'ding_nodelist_mini',
            14 => 'ding_list_large',
          ),
          'apply_all_effects' => 1,
          'fallback_style' => '',
        ),
        'weight' => 0,
      ),
      21 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 560,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      25 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 392,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: ding_nodelist_mini.
  $styles['ding_nodelist_mini'] = array(
    'name' => 'ding_nodelist_mini',
    'label' => 'ding_nodelist_mini',
    'effects' => array(
      13 => array(
        'label' => 'Manual Crop: Custom crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 260,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'ding_nodelist_mini',
        ),
        'weight' => 0,
      ),
      11 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 260,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 260,
          'height' => 192,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ding_nodelist_mini_reused.
  $styles['ding_nodelist_mini_reused'] = array(
    'name' => 'ding_nodelist_mini_reused',
    'label' => 'ding_nodelist_mini_reused',
    'effects' => array(
      14 => array(
        'label' => 'Manual Crop: Automatically reuse cropped style',
        'help' => 'Load the first applied crop selection and reuse it.',
        'effect callback' => 'manualcrop_auto_reuse_effect',
        'form callback' => 'manualcrop_auto_reuse_form',
        'summary theme' => 'manualcrop_auto_reuse_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_auto_reuse',
        'data' => array(
          'style_priority' => array(
            0 => 'ding_nodelist_mini',
            1 => 'ting_cover_large',
            2 => 'ting_cover_medium',
            3 => 'ting_cover_small',
            4 => 'ding_tabroll_large',
            5 => 'ding_list_large',
            6 => 'ding_panorama_primary_large',
            7 => 'ding_primary_large',
            8 => 'ding_nodelist_extra_medium',
            9 => 'ding_nodelist_large',
            10 => 'ding_nodelist_medium',
            11 => 'ding_nodelist_pn_large',
            12 => 'ding_nodelist_pn_medium',
            13 => 'ding_nodelist_pn_small',
            14 => 'ding_nodelist_small',
          ),
          'apply_all_effects' => 1,
          'fallback_style' => '',
        ),
        'weight' => 0,
      ),
      29 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 260,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      30 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 260,
          'height' => 192,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: ding_nodelist_pn_large.
  $styles['ding_nodelist_pn_large'] = array(
    'name' => 'ding_nodelist_pn_large',
    'label' => 'ding_nodelist_pn_large',
    'effects' => array(
      19 => array(
        'label' => 'Manual Crop: Custom crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 920,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'ding_nodelist_pn_large',
        ),
        'weight' => 0,
      ),
      17 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 920,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      18 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 920,
          'height' => 420,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ding_nodelist_pn_large_reused.
  $styles['ding_nodelist_pn_large_reused'] = array(
    'name' => 'ding_nodelist_pn_large_reused',
    'label' => 'ding_nodelist_pn_large_reused',
    'effects' => array(
      15 => array(
        'label' => 'Manual Crop: Automatically reuse cropped style',
        'help' => 'Load the first applied crop selection and reuse it.',
        'effect callback' => 'manualcrop_auto_reuse_effect',
        'form callback' => 'manualcrop_auto_reuse_form',
        'summary theme' => 'manualcrop_auto_reuse_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_auto_reuse',
        'data' => array(
          'style_priority' => array(
            0 => 'ding_nodelist_pn_large',
            1 => 'ting_cover_small',
            2 => 'ding_list_large',
            3 => 'ding_panorama_primary_large',
            4 => 'ting_cover_medium',
            5 => 'ding_primary_large',
            6 => 'ding_nodelist_extra_medium',
            7 => 'ding_nodelist_large',
            8 => 'ding_nodelist_medium',
            9 => 'ding_nodelist_mini',
            10 => 'ding_nodelist_pn_medium',
            11 => 'ding_nodelist_pn_small',
            12 => 'ding_nodelist_small',
            13 => 'ding_tabroll_large',
            14 => 'ting_cover_large',
          ),
          'apply_all_effects' => 1,
          'fallback_style' => '',
        ),
        'weight' => 0,
      ),
      19 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 920,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      20 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 920,
          'height' => 420,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: ding_nodelist_pn_medium.
  $styles['ding_nodelist_pn_medium'] = array(
    'name' => 'ding_nodelist_pn_medium',
    'label' => 'ding_nodelist_pn_medium',
    'effects' => array(
      22 => array(
        'label' => 'Manual Crop: Custom crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 690,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'ding_nodelist_pn_medium',
        ),
        'weight' => 0,
      ),
      20 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 690,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      21 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 690,
          'height' => 320,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ding_nodelist_pn_small.
  $styles['ding_nodelist_pn_small'] = array(
    'name' => 'ding_nodelist_pn_small',
    'label' => 'ding_nodelist_pn_small',
    'effects' => array(
      25 => array(
        'label' => 'Manual Crop: Custom crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 340,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'ding_nodelist_pn_small',
        ),
        'weight' => 0,
      ),
      23 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 340,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      24 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 340,
          'height' => 160,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ding_nodelist_small.
  $styles['ding_nodelist_small'] = array(
    'name' => 'ding_nodelist_small',
    'label' => 'ding_nodelist_small',
    'effects' => array(
      16 => array(
        'label' => 'Manual Crop: Custom crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 360,
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'ding_nodelist_small',
        ),
        'weight' => 0,
      ),
      14 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 360,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      15 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 266,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: ding_tabroll_large_reused.
  $styles['ding_tabroll_large_reused'] = array(
    'name' => 'ding_tabroll_large_reused',
    'label' => 'ding_tabroll_large_reused',
    'effects' => array(
      13 => array(
        'label' => 'Manual Crop: Automatically reuse cropped style',
        'help' => 'Load the first applied crop selection and reuse it.',
        'effect callback' => 'manualcrop_auto_reuse_effect',
        'form callback' => 'manualcrop_auto_reuse_form',
        'summary theme' => 'manualcrop_auto_reuse_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_auto_reuse',
        'data' => array(
          'style_priority' => array(
            0 => 'ding_tabroll_large',
            1 => 'ting_cover_large',
            2 => 'ting_cover_medium',
            3 => 'ting_cover_small',
            4 => 'ding_nodelist_small',
            5 => 'ding_list_large',
            6 => 'ding_panorama_primary_large',
            7 => 'ding_primary_large',
            8 => 'ding_nodelist_extra_medium',
            9 => 'ding_nodelist_large',
            10 => 'ding_nodelist_medium',
            11 => 'ding_nodelist_mini',
            12 => 'ding_nodelist_pn_large',
            13 => 'ding_nodelist_pn_medium',
            14 => 'ding_nodelist_pn_small',
          ),
          'apply_all_effects' => 1,
          'fallback_style' => '',
        ),
        'weight' => 0,
      ),
      31 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 400,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
