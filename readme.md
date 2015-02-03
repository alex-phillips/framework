```
 ______  ______   ______   __    __   ______   __    __   ______   ______   __  __    
/\  ___\/\  __ \ /\  __ \ /\ '-./  \ /\  ___\ /\ \ __\ \ /\  __ \ /\  __ \ /\ \/ /_   
\ \  __\\ \  __< \ \  __ \\ \ \._/\ \\ \  __\ \ \ \| \\ \\ \ \/\ \\ \  __< \ \  _  \  
 \ \_\/  \ \_\ \_\\ \_\ \_\\ \_\/\ \_\\ \_____\\ \__/_.__\\ \_____\\ \_\ \_\\ \_\ \_\ 
  \/_/    \/_/\/_/ \/_/\/_/ \/_/  \/_/ \/_____/ \/_/  \/_/ \/_____/ \/_/\/_/ \/_/\/_/ 
```

# Framework #
[![Project Titon](https://img.shields.io/badge/project-titon-82667d.svg?style=flat)](http://titon.io)
[![Build Status](https://img.shields.io/travis/titon/framework.svg?style=flat)](https://travis-ci.org/titon/framework)
[![HHVM](https://img.shields.io/hhvm/titon/framework.svg?style=flat)](https://github.com/titon/framework)
[![Latest Version](https://img.shields.io/packagist/v/titon/framework.svg?style=flat)](https://packagist.org/packages/titon/framework)
[![Total Downloads](https://img.shields.io/packagist/dm/titon/framework.svg?style=flat)](https://packagist.org/packages/titon/framework)
[![License](https://img.shields.io/packagist/l/titon/framework.svg?style=flat)](https://github.com/titon/framework/blob/master/license.md)

## What is Titon? ##

Titon is a full-stack web framework built on Hack that runs in HHVM. It is written with simplicity and efficiency in mind,
with enough room for extensibility and abstraction. The framework takes advantage of Hack's strict mode, type system,
generics, collections, and more. It also integrates the wonderful PSRs from PHP-FIG for increased interoperability
with external PHP code bases and libraries.

Looking for more information? Find us in [#titon](http://webchat.freenode.net/?channels=titon) on FreeNode.

#### Unported Packages ####

* [db](https://github.com/titon/db)
* [db-mysql](https://github.com/titon/db-mysql)
* [db-postgresql](https://github.com/titon/db-postgresql)
* [db-sqlite](https://github.com/titon/db-sqlite)
* [db-mongodb](https://github.com/titon/db-mongodb)
* [model](https://github.com/titon/model)
* [mvc](https://github.com/titon/mvc)
* [g11n](https://github.com/titon/g11n)

#### Upcoming Packages ####

* Auth
* ACL
* Dependency/Service Containers
* Session
* Kernel
* ADR
* Mail
* Queue

## Roadmap ##

Upcoming features and release plan.

* January
    * Documentation
* February
    * Context package - Dependency containers and service locators
    * Add a `Debug\Dumper` class that supports HTML and CLI
    * Add a `Type\Yaml` class for parsing YAML documents
* March
    * Kernel package - Application foundation
    * MVC package - Model-view-controller application
* April - May
    * G11N package - Internationalization and localization
* June
    * DB package - Database abstraction layer
* July
    * Model package - Object relational mapper and active record for DB entities
    * Beta release
* August
    * Session package - Custom session handler
* September
    * Queue package - Queue, job, and worker services
* October
    * Mail package - Emailing layer
* November
    * Auth package - Authentication and authorization
* December
    * ACL package - Access control lists
* January
    * ADR package - Action-domain-responder application
    * 0.1.0 release

## Requirements ##

Titon is built on the powerful [Hack language](http://hacklang.org/) and requires [HHVM 3.4.0+](http://hhvm.com/) 
as well as [Composer](http://getcomposer.org) for its autoloader.

## Usage ##

Since the project is heavy in development, there currently exists no documentation or installation process.
Feel free to mess around with the code or stay tuned for any updates.

## Contributing ##

Titon is looking for any knowledgable PHP developers that are looking to get their feet wet in Hack.
Chat with us over in [#titon](http://webchat.freenode.net/?channels=titon) for more information.

## Testing ##

Titon comes packaged with a Vagrant box and a handful of Python scripts to ease the testing process.
Boot up the Vagrant instance with `vagrant up` and SSH into the box with `vagrant ssh`.
Once in Vagrant, you can run the following command to run all tests.

```bash
/vagrant/bin/run-tests
```

Or run tests for a single file or folder.

```bash
/vagrant/bin/run-tests --path=Titon/Common
```

Or filter tests based on class or method name.

```bash
/vagrant/bin/run-tests --filter=methodName
```

#### Hack Strict Mode ####

For the most part, Titon strives to be strict mode only. This can be very challenging, but with Hack's built-in type checker,
it couldn't be easier. Simply run the following command to check for strict issues.

```bash
/vagrant/bin/type-check
```

Or type check a specific folder.

```bash
/vagrant/bin/type-check --path=Titon/Utility
```

When filtering down by path, multiple errors will still arise like "Was expecting a class", "Unbound name",
"Unbound global constant", "This is not a container, this is an object of type X", etc. The main cause of this issue 
is that the type checker is ran in a sub-folder, and not the root, so all those classes are not in scope. 
This should not be an issue if the type checker is ran in the source root.
