<?hh
/**
 * @copyright   2010-2015, The Titon Project
 * @license     http://opensource.org/licenses/bsd-license.php
 * @link        http://titon.io
 */

use Titon\Environment\Environment;

/**
 * --------------------------------------------------------------
 *  Type Aliases
 * --------------------------------------------------------------
 *
 * Defines type aliases that are used by the environment package.
 */

namespace Titon\Environment {
    type BootstrapperList = Vector<Bootstrapper>;
    type HostMap = Map<string, Host>;
    type HostnameList = Vector<string>;
    type VariableMap = Map<string, string>;
}

/**
 * --------------------------------------------------------------
 *  Helper Functions
 * --------------------------------------------------------------
 *
 * Defines global helper functions for common use cases.
 */

namespace {
    use Titon\Context\Depository;

    /**
     * @see Titon\Environment\Environment::getVariable()
     */
    function env(string $key): string {
        // UNSAFE
        // Since we're not type checking the response from the container.
        return Depository::getInstance()
            ->make('Titon\Environment\Environment')
            ->getVariable($key);
    }
}
