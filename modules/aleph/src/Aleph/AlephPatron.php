<?php

namespace Drupal\aleph\Aleph;

/**
 * @file
 * Provides the AlephPatron.
 */

use Drupal\aleph\Aleph\Handler\AlephPatronHandler;

/**
 * Class AlephPatron.
 */
class AlephPatron extends AlephPatronHandler {

  private $borId;
  private $verification;
  private $name;

  /**
   * Return the patron's name.
   *
   * @return string
   *    The patron's name.
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Set the patron's name.
   *
   * @param string $name
   *    The patron's name.
   */
  public function setName($name) {
    $this->name = $name;
  }

  /**
   * Returns the patron's ID.
   *
   * @return string
   *    The bor_id.
   */
  public function getId() {
    return $this->borId;
  }

  /**
   * Set the patron's ID.
   *
   * @param string $bor_id
   *    The patron's ID.
   */
  public function setId($bor_id) {
    $this->borId = $bor_id;
  }

  /**
   * Get the verification code.
   *
   * @return string
   *    The pin/verification code.
   */
  public function getVerification() {
    return $this->verification;
  }

  /**
   * Set verification for patron.
   *
   * @param string $verification
   *    The patron's pin code.
   */
  public function setVerification($verification) {
    $this->verification = $verification;
  }

}
