#
#  Be sure to run `pod spec lint JKADSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "JKADSDK"
  s.version      = "0.0.1"
  s.summary      = "ad sdk"

  s.description  = <<-DESC
                   jike ad sdk
                   DESC

  s.homepage     = "https://github.com/yahua119"

  s.license      = "MIT"

  s.author             = { "yahua119" => "1286034772@qq.com" }
  
  s.requires_arc = true

  s.source       = { :git => "https://github.com/yahua119/JKADSDK.git", :tag => "#{s.version}" }



  s.default_subspec = 'frameworks'
  s.subspec 'frameworks' do |subspec|
    subspec.preserve_path     =  'JKADSDK/*.framework' 
  end

  s.resources = 'JKADSDK/*.bundle'
  
  s.ios.deployment_target = '7.0'

  s.frameworks = "Foundation", "UIKit"

end
