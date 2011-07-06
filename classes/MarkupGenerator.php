<?php
/**
 * @file
 * An attribute markup generator.
 *
 * @author Jani Palsamäki
 */
 
class MarkupGenerator {

  public function generateAttribute($name, $value) {
    return $name != NULL && $value != NULL ? check_plain($name) . '="' . $value  . '"' : '';
  }
}
