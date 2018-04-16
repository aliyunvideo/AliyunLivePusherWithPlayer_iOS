Pod::Spec.new do |s|

  s.name         = "AlivcLivePusherWithPlayer"
  s.version      = "3.3.3"
  s.summary      = "AlivcLivePusherWithPlayer_iOS"
  s.description  = <<-DESC
                   It's an SDK for aliyun video vodplay, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyunvideo/AliyunLivePusherWithPlayer_iOS.git"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "videosdk@service.aliyun.com"}
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/aliyunvideo/AliyunLivePusherWithPlayer_iOS.git", :tag => "#{s.version}" }

  s.subspec 'AlivcLivePusherWithPlayer' do |pusher_playersdk|
  pusher_playersdk.vendored_frameworks = 'AlivcLivePusher.framework','AlivcLibRtmp.framework','AliyunPlayerSDK.framework','AlivcLibBeauty.framework','AlivcLibFace.framework'
  pusher_playersdk.resource = 'AlivcLibFaceResource.bundle','AliyunLanguageSource.bundle'
# pusher_playersdk.frameworks = 'MediaPlayer','CoreGraphics'
  end

end
