<?hh
namespace Titon\Debug\Annotation;

use Titon\Annotation\WiresAnnotations;
use Titon\Debug\Debugger;
use Titon\Debug\Logger;
use Titon\Test\TestCase;
use DateTime;

class DeprecatedTest extends TestCase {

    protected function setUp() {
        parent::setUp();

        $this->setupVFS();
        $this->vfs->createDirectory('/logs/');

        Debugger::setLogger(new Logger($this->vfs->path('/logs/')));
    }

    public function testMessageIsLoggedWhenClassIsInstantiated() {
        $path = '/logs/notice-' . date('Y-m-d') . '.log';

        $this->assertFileNotExists($this->vfs->path($path));

        $stub = new DeprecatedStub();

        $this->assertFileExists($this->vfs->path($path));

        $this->assertRegExp('/^\[' . self::DATE_RFC3339_REGEX . '\] ' . preg_quote('Titon\Debug\Annotation\DeprecatedStub', '/') . ' is deprecated\. This is the error message\./', file_get_contents($this->vfs->path($path)));
    }

}

<<Deprecated('This is the error message.')>>
class DeprecatedStub {
    use WiresAnnotations;

    public function __construct() {
        $this->wireClassAnnotation('Deprecated');
    }
}
