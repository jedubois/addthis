<?php
/**
 * @file
 * An AddThis-class.
 *
 * @author Jani Palsamäki
 */

class AddThis {

  const WIDGET_TYPE_DISABLED = 'disabled';
  const WIDGET_TYPE_COMPACT_BUTTON = 'compact_button';
  const WIDGET_TYPE_LARGE_BUTTON = 'large_button';
  const WIDGET_TYPE_TOOLBOX = 'toolbox';
  const WIDGET_TYPE_SHARECOUNT = 'sharecount';

  public static function getWidgetTypes() {
    return array(
      self::WIDGET_TYPE_DISABLED => t('Disabled'),
      self::WIDGET_TYPE_COMPACT_BUTTON => t('Compact button'),
      self::WIDGET_TYPE_LARGE_BUTTON => t('Large button'),
      self::WIDGET_TYPE_TOOLBOX => t('Toolbox'),
      self::WIDGET_TYPE_SHARECOUNT => t('Sharecount'),
    );
  }

  public static function getWidgetType() {
    return variable_get('addthis_block_widget_type', self::WIDGET_TYPE_COMPACT_BUTTON);
  }

  public static function getWidgetMarkup($widgetType = '') {
    $username = self::getUsername();
    switch ($widgetType) {
      case self::WIDGET_TYPE_LARGE_BUTTON:
        $markup = sprintf(
          '<a class="addthis_button" href="http://www.addthis.com/bookmark.php?v=250&amp;username=%s"><img src="http://s7.addthis.com/static/btn/v2/lg-share-en.gif" width="125" height="16" alt="Bookmark and Share" style="border:0"/></a><script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#username=%s"></script>',
          $username, $username
        );
        break;
      case self::WIDGET_TYPE_COMPACT_BUTTON:
        $markup = sprintf(
          '<a class="addthis_button" href="http://www.addthis.com/bookmark.php?v=250&amp;username=%s"><img src="http://s7.addthis.com/static/btn/sm-share-en.gif" width="83" height="16" alt="Bookmark and Share" style="border:0"/></a><script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#username=%s"></script>',
          $username, $username
        );
        break;
      case self::WIDGET_TYPE_TOOLBOX:
        $markup = sprintf(
          '<div class="addthis_toolbox addthis_default_style"><a href="http://www.addthis.com/bookmark.php?v=250&amp;username=%s" class="addthis_button_compact">Share</a><span class="addthis_separator">|</span><a class="addthis_button_preferred_1"></a><a class="addthis_button_preferred_2"></a><a class="addthis_button_preferred_3"></a><a class="addthis_button_preferred_4"></a></div><script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#username=%s"></script>',
          $username, $username
        );
        break;
      case self::WIDGET_TYPE_SHARECOUNT:
        $markup = sprintf('<div class="addthis_toolbox addthis_default_style"><a class="addthis_counter"></a></div><script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#username=%s"></script>',
          $username
        );
        break;
      default:
        $markup = '';
        break;
    }
    return $markup;
  }

  private static function getUsername() {
    return variable_get('addthis_username', '');
  }
}