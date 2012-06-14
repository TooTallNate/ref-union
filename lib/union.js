
/**
 * Module dependencies.
 */

var ref = require('ref')
var assert = require('assert')
var debug = require('debug')('ref-union')

/**
 * The "Union" type constructor.
 */

function Union () {
  debug('defining new union "type"')

  function UnionType (arg, data) {

  }

  // make instances inherit from `proto`
  UnionType.prototype = Object.create(proto, {
    constructor: {
        value: UnionType
      , enumerable: false
      , writable: true
      , configurable: true
    }
  })

  UnionType.defineProperty = defineProperty
  UnionType.toString = toString

  // comply with ref's "type" interface
  UnionType.size = 0
  UnionType.alignment = 0
  UnionType.indirection = 1
  UnionType.get = get
  UnionType.set = set

  return UnionType
}
module.exports = Union


function defineProperty (name, type) {

}

function toString () {
  return '[UnionType]'
}

function get (buffer, offset) {

}

function set (buffer, offset, value) {

}


/**
 * the base prototype that union type instances will inherit from.
 */

var proto = {}

proto._pointer = ref.NULL

/**
 * returns a Buffer pointing to this union data structure.
 */

proto.ref = function ref () {
  return this._pointer
}
